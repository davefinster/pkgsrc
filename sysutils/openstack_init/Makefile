# $NetBSD: Makefile,v 1.2 2014/05/17 16:10:49 wiz Exp $
#

DISTNAME=	openstack_init-1.0
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Autoconfigure NetBSD VM on OpenStack
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

do-extract:
	cd ${FILESDIR} && cp *.py *.sh ${WRKSRC}/

RCD_SCRIPTS=	xen_network openstack_init

do-install:
	${INSTALL_PROGRAM_DIR}	${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/xen_network.py ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/openstack_init.py ${DESTDIR}${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
