# $NetBSD: Makefile,v 1.17 2014/06/01 16:35:32 wiz Exp $
#

DISTNAME=	artwiz-aleczapka-1.3
PKGNAME=	${DISTNAME:S/aleczapka/fonts/}
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	http://fluxbox.org/artwiz-aleczapka/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vastwaters.com/
COMMENT=	Set of free fonts for X11 desktops

WRKSRC=		${WRKDIR}/artwiz-aleczapka
USE_X11BASE=	yes

NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/artwiz
REQD_DIRS=	${PREFIX}/share/fonts/X11/artwiz

INSTALLATION_DIRS=	share/fonts/X11/artwiz

do-install:
	for i in ${WRKSRC}/*.pcf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIRS.x11}; \
	done

.include "../../mk/bsd.pkg.mk"
