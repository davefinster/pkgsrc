# $NetBSD: Makefile,v 1.22 2014/12/01 12:39:17 joerg Exp $

DISTNAME=	libdvbpsi-1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvbpsi/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/
COMMENT=	PSI decoder and generator library for MPEG2 and DVB streams
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libdvbpsi.pc.in

LIBS.SunOS+=	-lsocket -lnsl

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=tautological-constant-out-of-range-compare \
			-Wno-error=tautological-compare
CWRAPPERS_APPEND.cc+=	-Wno-error=tautological-constant-out-of-range-compare \
			-Wno-error=tautological-compare
.endif

.include "../../mk/bsd.pkg.mk"
