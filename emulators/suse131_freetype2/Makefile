# $NetBSD: Makefile,v 1.2 2014/09/07 12:26:42 obache Exp $

PKGNAME=	suse_freetype2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libfreetype6-2.5.0.1-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for freetype-2.x

EMUL_MODULES.linux=	base png

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
