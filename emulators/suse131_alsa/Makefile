# $NetBSD: Makefile,v 1.4 2014/11/03 09:04:20 obache Exp $

PKGNAME=	suse_alsa-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	alsa-1.0.27.2-3.5.1.${SUSE_ARCH}
RPMUPDPKGS+=	alsa-oss-1.0.25-8.4.1.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-1.0.27-3.1.1.${SUSE_ARCH}
RPMPKGS+=	alsa-plugins-pulse-1.0.27-3.1.1.${SUSE_ARCH}
RPMUPDPKGS+=	alsa-utils-1.0.27.2-4.5.1.${SUSE_ARCH}
RPMUPDPKGS+=	libasound2-1.0.27.2-3.5.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for ALSA

EMUL_MODULES.linux=	base pulseaudio

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

post-install:
	${INSTALL_DATA} ${FILESDIR}/60-oss.conf \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/share/alsa/alsa.conf.d/
	${SED} -e 's/"sysdefault"/"oss"/g' \
		< ${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/asound-pulse.conf \
		> ${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/asound.conf

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
