# $NetBSD: Makefile,v 1.40 2015/02/01 09:07:40 obache Exp $

DISTNAME=		openntpd-5.7p3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp3.usa.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp.jaist.ac.jp/pub/OpenBSD/OpenNTPD/


MAINTAINER=		henson@acm.org
HOMEPAGE=		http://www.openntpd.org/
COMMENT=		Free implementation of the Network Time Protocol
LICENSE=		isc

CONFLICTS+=		ntp-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-privsep-path=path=${VARBASE}/chroot/ntpd

SUBST_CLASSES+=		ntpd_m
SUBST_STAGE.ntpd_m=	pre-build
SUBST_FILES.ntpd_m=	ntpd.8 ntpctl.8
SUBST_SED.ntpd_m+=	-e 's,/var/db/,${VARBASE}/db/openntpd/,g'
SUBST_SED.ntpd_m+=	-e 's,/var/run/,${VARBASE}/run/,g'

SUBST_CLASSES+=		ntpd_h
SUBST_STAGE.ntpd_h=	pre-build
SUBST_FILES.ntpd_h=	ntpd.h
SUBST_SED.ntpd_h+=	-e 's,/db/ntpd.drift,/db/openntpd/ntpd.drift,g'

EGDIR=			${PREFIX}/share/examples/openntpd
CONF_FILES=		${EGDIR}/ntpd.conf ${PKG_SYSCONFDIR}/ntpd.conf

RCD_SCRIPTS=		openntpd
PKG_GROUPS=		_ntp
PKG_USERS=		_ntp:_ntp
PKG_HOME._ntp=		${VARBASE}/chroot/ntpd

BUILD_DEFS+=		VARBASE

OWN_DIRS=		${VARBASE}/chroot/ntpd ${VARBASE}/db/openntpd
AUTO_MKDIRS=		yes

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${DESTDIR}${PREFIX}/sbin/ntpd
	ln ${DESTDIR}${PREFIX}/sbin/ntpd ${DESTDIR}${PREFIX}/sbin/ntpctl
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ntpd.8
	${INSTALL_MAN} ${WRKSRC}/ntpctl.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ntpctl.8
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ntpd.conf.5
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${DESTDIR}${EGDIR}/ntpd.conf

.include "../../mk/bsd.pkg.mk"
