# $NetBSD: Makefile,v 1.32 2015/01/04 05:58:35 obache Exp $
#

DISTNAME=	mod_dnssd-0.6
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/mod_dnssd/
COMMENT=	Apache module which adds Zeroconf support via DNS-SD using Avahi
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CONFIGURE_ENV+=		APXS=${APXS:Q}
CONFIGURE_ARGS+=	--disable-lynx

APACHE_MODULE_NAME=	mod_dnssd
APACHE_MODULE=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	cd ${WRKSRC}/src &&						\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&			\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 	\
	      -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
