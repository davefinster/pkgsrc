# $NetBSD: Makefile,v 1.12 2014/10/09 14:06:00 wiz Exp $

DISTNAME=	nttcp-1.47
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://home.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIB="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} nttcp \
		${DESTDIR}${PREFIX}/bin/nttcp
	cd ${WRKSRC} && ${INSTALL_MAN} nttcp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
