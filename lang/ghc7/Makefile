# $NetBSD: Makefile,v 1.14 2015/02/04 06:53:18 pho Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-7.6.3-src
PKGNAME=	${DISTNAME:S/-src$//}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell
LICENSE=	modified-bsd

# GHC requires GHC to build itself. Formerly we could work around this
# bootstrapping problem by creating a special archive containing C
# sources compiled from Haskell sources, but that's no longer
# possible. So we have to prepare stripped-down binaries sufficient to
# bootstrap compilers for each platforms. If you want to build them
# yourself, follow an instruction in the ./TODO file.
ONLY_FOR_PLATFORM= \
	Darwin-*-powerpc \
	FreeBSD-*-i386 \
	Linux-*-x86_64 \
	NetBSD-*-i386 \
	NetBSD-*-x86_64 \
	SunOS-5.11-*


# -----------------------------------------------------------------------------
# Distfiles
#
DISTFILES=	${DEFAULT_DISTFILES}
#.if make(distinfo)
#DISTFILES+=	${PKGNAME_NOREV}-boot-i386-unknown-freebsd.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-i386-unknown-netbsd.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-powerpc-apple-darwin.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-x86_64-unknown-linux.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-x86_64-unknown-netbsd.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-i386-unknown-solaris2.tar.xz
#DISTFILES+=	${PKGNAME_NOREV}-boot-x86_64-unknown-solaris2.tar.xz
#.else
#DISTFILES+=	${BOOT_ARCHIVE}
#.endif

.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DEFAULT_DISTFILES}


# -----------------------------------------------------------------------------
# Tools
#
USE_TOOLS+=			autoconf gmake perl:run
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=		no
USE_LIBTOOL=			yes

CONFIGURE_ARGS+= \
	--with-gcc=${CC:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp:Q}/${BUILDLINK_INCDIRS.gmp:Q} \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp:Q}/${BUILDLINK_LIBDIRS.gmp:Q} \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv:Q}/${BUILDLINK_INCDIRS.iconv:Q} \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv:Q}/${BUILDLINK_LIBDIRS.iconv:Q}

CONFIGURE_ENV+= \
	ac_cv_path_fp_prog_ar=${AR:Q} \
	PerlCmd=${PERL5:Q}

# CFLAGS and LDFLAGS are currently not honored by "./configure". Since
# LDFLAGS contains rpath flags it's very important to force GHC to
# honor it. Otherwise neither GHC itself nor executables it produces
# will have any rpaths so users will have to put "${PREFIX}/lib" into
# their "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
.for stage in 0 1 2
CONFIGURE_ENV+= \
	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:Q} \
	CONF_GCC_LINKER_OPTS_STAGE${stage}=${LDFLAGS:Q} \
	CONF_LD_LINKER_OPTS_STAGE${stage}=${LDFLAGS:Q}
.endfor


# -----------------------------------------------------------------------------
# Build hooks
#

# We patch configure.ac in some directories.
post-patch:
	@${PHASE_MSG} "Regenerating configuration scripts for ${PKGNAME}"
	${RUN} cd ${WRKSRC:Q}/libraries/base        && autoconf
	${RUN} cd ${WRKSRC:Q}/libraries/integer-gmp && autoconf


# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../lang/ghc7/bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.


# Here we generate mk/build.mk dynamically.
post-configure:
	${RUN} ${RM} -f ${WRKSRC:Q}/mk/build.mk

# We need to tell the libraries/terminfo/configure that our ncurses is
# in a non-standard path. Without that, the resulting GHC tries to
# link programs by executing ld(1) without passing it -L${PREFIX:Q}/lib.
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
		--configure-option=--with-curses-includes=${BUILDLINK_PREFIX.curses:Q}/${BUILDLINK_INCDIRS.curses:Q} \
		--configure-option=--with-curses-libraries=${BUILDLINK_PREFIX.curses:Q}/${BUILDLINK_LIBDIRS.curses:Q}" \
		>> ${WRKSRC:Q}/mk/build.mk

# The ghc compiler does normally split the generated asm files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
	${RUN} ${ECHO} "SplitObjs         = NO" >> ${WRKSRC:Q}/mk/build.mk

# If there is HsColour in the PATH, GHC's build system tries to use it
# without even checking if it really works. That's not what we
# appreciate.
	${RUN} ${ECHO} "HSCOLOUR_SRCS     = NO" >> ${WRKSRC:Q}/mk/build.mk

# Don't even think of PDF.
	${RUN} ${ECHO} "BUILD_DOCBOOK_PS  = NO" >> ${WRKSRC:Q}/mk/build.mk
	${RUN} ${ECHO} "BUILD_DOCBOOK_PDF = NO" >> ${WRKSRC:Q}/mk/build.mk


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	GHC_VERSION=${PKGVERSION_NOREV}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/lib/${PKGNAME_NOREV}/package.conf.d/package.cache


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs some files
# whose names are randomly generated, namely
# lib/${PKGNAME}/package.conf.d/*.conf
#
PRINT_PLIST_AWK+=	/lib\/${PKGNAME_NOREV}\/package\.conf\.d/ { next; }

# If we were lucky we could just use "PLIST_TYPE = dynamic", but the
# feature has seemingly bitrotted.
.include "../../mk/bsd.prefs.mk"
.if empty(USE_DESTDIR:M[Yy][Ee][Ss])
GENERATE_PLIST+= \
	cd ${PREFIX:Q} && \
		${FIND} lib/${PKGNAME_NOREV}/package.conf.d -xdev -newer ${_COOKIE.extract} \! -type d -print | ${SORT} -d;
.else
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} lib/${PKGNAME_NOREV}/package.conf.d -xdev \! -type d -print | ${SORT} -d;
.endif


# -----------------------------------------------------------------------------
# Sanity checks
#

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# Dynamic Haskell libraries currently have no rpaths to any dependent
# Haskell libraries so we must skip shlibs check for them. Note that
# the situation seems to be changed in GHC 7.8.1 so we should
# readdress this later. See
# https://ghc.haskell.org/trac/ghc/ticket/8266 (slightly off-topic but
# pho@ found no description for the -fuse-rpath flag.)
.if !empty(PKGNAME:Mghc-7.6.*)
CHECK_SHLIBS_SKIP+=		*/libHS*-ghc${PKGVERSION_NOREV}.*
.endif


# -----------------------------------------------------------------------------
# Dependencies
#

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
