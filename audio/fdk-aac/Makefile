# $NetBSD: Makefile,v 1.1 2014/11/30 18:58:43 adam Exp $

DISTNAME=	fdk-aac-0.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencore-amr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/opencore-amr/
COMMENT=	Fraunhofer FDK AAC Codec Library
LICENSE=	fraunhofer-license

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fdk-aac.pc.in

.include "../../mk/bsd.pkg.mk"
