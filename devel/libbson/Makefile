# $NetBSD: Makefile,v 1.6 2014/12/12 11:29:32 fhajny Exp $

DISTNAME=	libbson-1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://github.com/mongodb/libbson/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/libbson/
COMMENT=	BSON utility library
LICENSE=	apache-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-man-pages=yes

PKGCONFIG_OVERRIDE+=	src/libbson-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
