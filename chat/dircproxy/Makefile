# $NetBSD: Makefile,v 1.25 2014/05/29 23:35:17 wiz Exp $

DISTNAME=	dircproxy-1.2.0-beta2
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	http://dircproxy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/dircproxy/
COMMENT=	Detachable internet relay chat proxy server (devel version)

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run

.include "options.mk"

CONFLICTS=		dircproxy<=1.1.0

REPLACE_PERL+=		contrib/log.pl contrib/privmsg-log.pl

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/dircproxy
CONF_FILES=		${EGDIR:Q}/dircproxyrc.sample \
			${PKG_SYSCONFDIR:Q}/dircproxyrc
RCD_SCRIPTS=		dircproxy

.include "../../mk/bsd.pkg.mk"
