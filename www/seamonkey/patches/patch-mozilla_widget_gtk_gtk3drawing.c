$NetBSD: patch-mozilla_widget_gtk_gtk3drawing.c,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/widget/gtk/gtk3drawing.c.orig	2014-12-03 06:23:27.000000000 +0000
+++ mozilla/widget/gtk/gtk3drawing.c
@@ -2105,6 +2105,21 @@ moz_gtk_get_tab_thickness(void)
     return border.top;
 }
 
+static void
+moz_gtk_tab_prepare_style_context(GtkStyleContext *style,
+                                  GtkTabFlags flags)
+{  
+  gtk_style_context_set_state(style, ((flags & MOZ_GTK_TAB_SELECTED) == 0) ? 
+                                        GTK_STATE_FLAG_NORMAL : 
+                                        GTK_STATE_FLAG_ACTIVE);
+  gtk_style_context_add_region(style, GTK_STYLE_REGION_TAB, 
+                                      (flags & MOZ_GTK_TAB_FIRST) ? 
+                                        GTK_REGION_FIRST : 0);
+  gtk_style_context_add_class(style, (flags & MOZ_GTK_TAB_BOTTOM) ? 
+                                        GTK_STYLE_CLASS_BOTTOM : 
+                                        GTK_STYLE_CLASS_TOP);
+}
+
 /* actual small tabs */
 static gint
 moz_gtk_tab_paint(cairo_t *cr, GdkRectangle* rect,
@@ -2117,22 +2132,35 @@ moz_gtk_tab_paint(cairo_t *cr, GdkRectan
      * tab appear physically attached to the tabpanel; see details below. */
 
     GtkStyleContext* style;
+    GdkRectangle tabRect;
     GdkRectangle focusRect;
     GdkRectangle backRect;
+    int initial_gap = 0;
 
     ensure_tab_widget();
     gtk_widget_set_direction(gTabWidget, direction);
 
     style = gtk_widget_get_style_context(gTabWidget);    
-    backRect = focusRect = *rect;
-
     gtk_style_context_save(style);
+    moz_gtk_tab_prepare_style_context(style, flags);
+
+    tabRect = *rect;
+
+    if (flags & MOZ_GTK_TAB_FIRST) {
+        gtk_widget_style_get (gTabWidget, "initial-gap", &initial_gap, NULL);
+        tabRect.width -= initial_gap;
+
+        if (direction != GTK_TEXT_DIR_RTL) {
+            tabRect.x += initial_gap;
+        }
+    }
+
+    focusRect = backRect = tabRect;
 
     if ((flags & MOZ_GTK_TAB_SELECTED) == 0) {
         /* Only draw the tab */
-        gtk_style_context_set_state(style, GTK_STATE_FLAG_NORMAL);
         gtk_render_extension(style, cr,
-                             rect->x, rect->y, rect->width, rect->height,
+                             tabRect.x, tabRect.y, tabRect.width, tabRect.height,
                             (flags & MOZ_GTK_TAB_BOTTOM) ?
                                 GTK_POS_TOP : GTK_POS_BOTTOM );
     } else {
@@ -2186,24 +2214,19 @@ moz_gtk_tab_paint(cairo_t *cr, GdkRectan
         gap_loffset = gap_roffset = 20; /* should be enough */
         if (flags & MOZ_GTK_TAB_FIRST) {
             if (direction == GTK_TEXT_DIR_RTL)
-                gap_roffset = 0;
+                gap_roffset = initial_gap;
             else
-                gap_loffset = 0;
+                gap_loffset = initial_gap;
         }
 
-        gtk_style_context_set_state(style, GTK_STATE_FLAG_ACTIVE);
-
-        /* Adwaita theme engine crashes without it (rhbz#713764) */
-        gtk_style_context_add_region(style, GTK_STYLE_REGION_TAB, 0);      
-
         if (flags & MOZ_GTK_TAB_BOTTOM) {
             /* Draw the tab on bottom */
             focusRect.y += gap_voffset;
             focusRect.height -= gap_voffset;
 
             gtk_render_extension(style, cr,
-                                 rect->x, rect->y + gap_voffset, rect->width,
-                                 rect->height - gap_voffset, GTK_POS_TOP);
+                                 tabRect.x, tabRect.y + gap_voffset, tabRect.width,
+                                 tabRect.height - gap_voffset, GTK_POS_TOP);
 
             gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
 
@@ -2219,38 +2242,39 @@ moz_gtk_tab_paint(cairo_t *cr, GdkRectan
             cairo_clip(cr);
 
             gtk_render_frame_gap(style, cr,
-                                 rect->x - gap_loffset,
-                                 rect->y + gap_voffset - 3 * gap_height,
-                                 rect->width + gap_loffset + gap_roffset,
+                                 tabRect.x - gap_loffset,
+                                 tabRect.y + gap_voffset - 3 * gap_height,
+                                 tabRect.width + gap_loffset + gap_roffset,
                                  3 * gap_height, GTK_POS_BOTTOM,
-                                 gap_loffset, gap_loffset + rect->width);
+                                 gap_loffset, gap_loffset + tabRect.width);
             cairo_restore(cr);
         } else {
             /* Draw the tab on top */
             focusRect.height -= gap_voffset;
             gtk_render_extension(style, cr,
-                                 rect->x, rect->y, rect->width,
-                                 rect->height - gap_voffset, GTK_POS_BOTTOM);
+                                 tabRect.x, tabRect.y, tabRect.width,
+                                 tabRect.height - gap_voffset, GTK_POS_BOTTOM);
 
             gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
 
-            backRect.y += (rect->height - gap_voffset);
+            backRect.y += (tabRect.height - gap_voffset);
             backRect.height = gap_height;
 
             /* Draw the gap; erase with background color before painting in
              * case theme does not */
             gtk_render_background(style, cr, backRect.x, backRect.y,
                                   backRect.width, backRect.height);
+
             cairo_save(cr);
             cairo_rectangle(cr, backRect.x, backRect.y, backRect.width, backRect.height);
             cairo_clip(cr);
 
             gtk_render_frame_gap(style, cr,
-                                 rect->x - gap_loffset,
-                                 rect->y + rect->height - gap_voffset,
-                                 rect->width + gap_loffset + gap_roffset,
+                                 tabRect.x - gap_loffset,
+                                 tabRect.y + tabRect.height - gap_voffset,
+                                 tabRect.width + gap_loffset + gap_roffset,
                                  3 * gap_height, GTK_POS_TOP,
-                                 gap_loffset, gap_loffset + rect->width);
+                                 gap_loffset, gap_loffset + tabRect.width);
             cairo_restore(cr);
         }
     }
@@ -2885,10 +2909,6 @@ moz_gtk_get_widget_border(GtkThemeWidget
                                       left, top, right, bottom);
             return MOZ_GTK_SUCCESS;
         }
-    case MOZ_GTK_TAB:
-        ensure_tab_widget();
-        w = gTabWidget;
-        break;
     /* These widgets have no borders, since they are not containers. */
     case MOZ_GTK_SPLITTER_HORIZONTAL:
     case MOZ_GTK_SPLITTER_VERTICAL:
@@ -2932,6 +2952,51 @@ moz_gtk_get_widget_border(GtkThemeWidget
 }
 
 gint
+moz_gtk_get_tab_border(gint* left, gint* top, gint* right, gint* bottom, 
+                       GtkTextDirection direction, GtkTabFlags flags)
+{
+    GtkStyleContext* style;    
+    int tab_curvature;
+
+    ensure_tab_widget();
+
+    style = gtk_widget_get_style_context(gTabWidget);
+    gtk_style_context_save(style);
+    moz_gtk_tab_prepare_style_context(style, flags);
+
+    // TODO add_style_border() should be replaced
+    // with focus-line-width and focus-padding
+    // see Bug 877605
+    *left = *top = *right = *bottom = 0;
+    moz_gtk_add_style_border(style, left, top, right, bottom);
+    moz_gtk_add_style_padding(style, left, top, right, bottom);
+
+    gtk_widget_style_get (gTabWidget, "tab-curvature", &tab_curvature, NULL);
+    *left += tab_curvature;
+    *right += tab_curvature;
+
+    if (flags & MOZ_GTK_TAB_FIRST) {
+      int initial_gap;
+      gtk_widget_style_get (gTabWidget, "initial-gap", &initial_gap, NULL);
+      if (direction == GTK_TEXT_DIR_RTL)
+      	*right += initial_gap;
+      else
+      	*left += initial_gap;
+    }
+
+    // Top tabs have no bottom border, bottom tabs have no top border
+    if (flags & MOZ_GTK_TAB_BOTTOM) {
+      *top = 0;
+    } else {
+      *bottom = 0;
+    }
+
+    gtk_style_context_restore(style);
+
+    return MOZ_GTK_SUCCESS;
+}
+
+gint
 moz_gtk_get_combo_box_entry_button_size(gint* width, gint* height)
 {
     /*
