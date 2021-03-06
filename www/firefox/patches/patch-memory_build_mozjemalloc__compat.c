$NetBSD: patch-memory_build_mozjemalloc__compat.c,v 1.1 2014/12/01 18:11:14 ryoon Exp $

--- memory/build/mozjemalloc_compat.c.orig	2014-11-21 03:37:44.000000000 +0000
+++ memory/build/mozjemalloc_compat.c
@@ -12,6 +12,8 @@
 #include "jemalloc_types.h"
 #include "mozilla/Types.h"
 
+#include <stdbool.h>
+
 #if defined(MOZ_NATIVE_JEMALLOC)
 
 MOZ_IMPORT_API int
@@ -47,6 +49,16 @@ je_(nallocm)(size_t *rsize, size_t size,
 	je_(mallctlbymib)(mib, miblen, &v, &sz, NULL, 0);		\
 } while (0)
 
+#define	CTL_IJ_GET(n, v, i, j) do {					\
+	size_t mib[6];							\
+	size_t miblen = sizeof(mib) / sizeof(mib[0]);			\
+	size_t sz = sizeof(v);						\
+	je_(mallctlnametomib)(n, mib, &miblen);				\
+	mib[2] = i;							\
+	mib[4] = j;							\
+	je_(mallctlbymib)(mib, miblen, &v, &sz, NULL, 0);			\
+} while (0)
+
 MOZ_MEMORY_API size_t
 malloc_good_size_impl(size_t size)
 {
@@ -61,6 +73,48 @@ malloc_good_size_impl(size_t size)
   return size;
 }
 
+static size_t
+compute_bin_unused(unsigned int narenas)
+{
+    size_t bin_unused = 0;
+
+    uint32_t nregs; // number of regions per run in the j-th bin
+    size_t reg_size; // size of regions served by the j-th bin
+    size_t curruns; // number of runs belonging to a bin
+    size_t curregs; // number of allocated regions in a bin
+
+    unsigned int nbins; // number of bins per arena
+    unsigned int i, j;
+
+    // curruns and curregs are not defined for uninitialized arenas,
+    // so we skip them when computing bin_unused. However, initialized
+    // arenas are not guaranteed to be sequential, so we must test each
+    // one when iterating below.
+    bool initialized[100]; // should be narenas, but MSVC doesn't have VLAs
+    size_t isz = sizeof(initialized) / sizeof(initialized[0]);
+
+    je_(mallctl)("arenas.initialized", initialized, &isz, NULL, 0);
+    CTL_GET("arenas.nbins", nbins);
+
+    for (j = 0; j < nbins; j++) {
+        CTL_I_GET("arenas.bin.0.nregs", nregs, j);
+        CTL_I_GET("arenas.bin.0.size", reg_size, j);
+
+        for (i = 0; i < narenas; i++) {
+            if (!initialized[i]) {
+                continue;
+            }
+
+            CTL_IJ_GET("stats.arenas.0.bins.0.curruns", curruns, i, j);
+            CTL_IJ_GET("stats.arenas.0.bins.0.curregs", curregs, i, j);
+
+            bin_unused += (nregs * curruns - curregs) * reg_size;
+        }
+    }
+
+    return bin_unused;
+}
+
 MOZ_JEMALLOC_API void
 jemalloc_stats_impl(jemalloc_stats_t *stats)
 {
@@ -68,6 +122,12 @@ jemalloc_stats_impl(jemalloc_stats_t *st
   size_t active, allocated, mapped, page, pdirty;
   size_t lg_chunk;
 
+  // Refresh jemalloc's stats by updating its epoch, see ctl_refresh in
+  // src/ctl.c
+  uint64_t epoch = 0;
+  size_t esz = sizeof(epoch);
+  int ret = je_(mallctl)("epoch", &epoch, &esz, &epoch, esz);
+
   CTL_GET("arenas.narenas", narenas);
   CTL_GET("arenas.page", page);
   CTL_GET("stats.active", active);
@@ -87,7 +147,8 @@ jemalloc_stats_impl(jemalloc_stats_t *st
   // We could get this value out of base.c::base_pages, but that really should
   // be an upstream change, so don't worry about it for now.
   stats->bookkeeping = 0;
-  stats->bin_unused = 0;
+
+  stats->bin_unused = compute_bin_unused(narenas);
 }
 
 MOZ_JEMALLOC_API void
