# $NetBSD: Makefile,v 1.9 2013/09/07 05:53:39 wiz Exp $

DISTNAME=	twm-1.0.8
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Tom's Window Manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config yacc

# Work around borked configure test in 1.0.7
CONFIGURE_ENV+=		ac_cv_prog_YACC=yacc

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
