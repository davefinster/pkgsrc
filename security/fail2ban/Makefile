# $NetBSD: Makefile,v 1.1 2015/02/09 10:05:25 nils Exp $
#

DISTNAME=	fail2ban-0.9.1
CATEGORIES=	security
MASTER_SITES=	-https://github.com/fail2ban/fail2ban/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.zip

MAINTAINER=	ahp-nils@users.sourceforge.net
HOMEPAGE=	http://www.fail2ban.org/
COMMENT=	Scans log files and bans IP that makes too many password failures
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
USE_TOOLS+=	make:build

USE_LANGUAGES=	# none
EGDIR=			${PREFIX}/share/examples/fail2ban
PKG_SYSCONFSUBDIR=	fail2ban
DOCDIR=			${PREFIX}/share/doc/fail2ban
OWN_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/ \
			${VARBASE}/run/fail2ban ${VARBASE}/db/fail2ban
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/ ${PKGMANDIR}/man5/ ${EGDIR} ${EGDIR}/action.d/ ${EGDIR}/filter.d/ \
			${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/

.for config in fail2ban.conf jail.conf paths-common.conf paths-debian.conf paths-fedora.conf paths-freebsd.conf paths-osx.conf paths-netbsd.conf paths-pkgsrc.conf
CONF_FILES+=		${EGDIR}/${config} ${PKG_SYSCONFDIR}/${config}
.endfor


.for action in apf.conf badips.conf badips.py blocklist_de.conf bsd-ipfw.conf cloudflare.conf complain.conf dshield.conf dummy.conf firewallcmd-ipset.conf firewallcmd-new.conf hostsdeny.conf ipfilter.conf ipfw.conf iptables-allports.conf iptables-common.conf iptables-ipset-proto4.conf iptables-ipset-proto6-allports.conf iptables-ipset-proto6.conf iptables-multiport-log.conf iptables-multiport.conf iptables-new.conf iptables-xt_recent-echo.conf iptables.conf mail-buffered.conf mail-whois-lines.conf mail-whois.conf mail.conf mynetwatchman.conf osx-afctl.conf osx-ipfw.conf pf.conf route.conf sendmail-buffered.conf sendmail-common.conf sendmail-whois-lines.conf sendmail-whois-ipjailmatches.conf sendmail-whois-ipmatches.conf sendmail-whois-matches.conf sendmail-whois.conf sendmail.conf shorewall.conf smtp.py symbiosis-blacklist-allports.conf ufw.conf xarf-login-attack.conf
CONF_FILES+=		${EGDIR}/action.d/${action} ${PKG_SYSCONFDIR}/action.d/${action}
.endfor

.for filter in 3proxy.conf apache-auth.conf apache-badbots.conf apache-botsearch.conf apache-common.conf apache-modsecurity.conf apache-nohome.conf apache-noscript.conf apache-overflows.conf apache-shellshock.conf assp.conf asterisk.conf common.conf counter-strike.conf courier-auth.conf courier-smtp.conf cyrus-imap.conf dovecot.conf directadmin.conf dropbear.conf ejabberd-auth.conf exim-common.conf exim-spam.conf exim.conf freeswitch.conf groupoffice.conf gssftpd.conf guacamole.conf horde.conf kerio.conf lighttpd-auth.conf monit.conf mysqld-auth.conf nagios.conf named-refused.conf nginx-http-auth.conf nsd.conf openwebmail.conf oracleims.conf pam-generic.conf perdition.conf php-url-fopen.conf portsentry.conf postfix-sasl.conf postfix.conf proftpd.conf pure-ftpd.conf qmail.conf recidive.conf roundcube-auth.conf selinux-common.conf selinux-ssh.conf sendmail-auth.conf sendmail-reject.conf sieve.conf sogo-auth.conf solid-pop3d.conf squid.conf squirrelmail.conf sshd-ddos.conf sshd.conf stunnel.conf suhosin.conf tine20.conf uwimap-auth.conf vsftpd.conf webmin-auth.conf wuftpd.conf xinetd-fail.conf
CONF_FILES+=		${EGDIR}/filter.d/${filter} ${PKG_SYSCONFDIR}/filter.d/${filter}
.endfor

TXTDOCFILES+=		develop.txt fail2ban.txt fail2ban.client.txt fail2ban.client.actionreader.txt fail2ban.client.beautifier.txt fail2ban.client.configparserinc.txt fail2ban.client.configreader.txt fail2ban.client.configurator.txt fail2ban.client.csocket.txt fail2ban.client.fail2banreader.txt fail2ban.client.filterreader.txt fail2ban.client.jailreader.txt fail2ban.exceptions.txt fail2ban.client.jailsreader.txt fail2ban.helpers.txt fail2ban.protocol.txt fail2ban.server.txt fail2ban.server.action.txt fail2ban.server.actions.txt fail2ban.server.asyncserver.txt fail2ban.server.banmanager.txt fail2ban.server.database.txt fail2ban.server.datedetector.txt fail2ban.server.datetemplate.txt fail2ban.server.faildata.txt fail2ban.server.failmanager.txt filters.txt fail2ban.server.failregex.txt fail2ban.server.filter.txt fail2ban.server.filtergamin.txt fail2ban.server.filterpoll.txt fail2ban.server.filterpyinotify.txt fail2ban.server.filtersystemd.txt fail2ban.server.jail.txt fail2ban.server.jails.txt fail2ban.server.jailthread.txt fail2ban.server.mytime.txt fail2ban.server.server.txt fail2ban.server.strptime.txt fail2ban.server.ticket.txt fail2ban.server.transmitter.txt fail2ban.version.txt index.txt release.txt

AUTO_MKDIRS=		yes
MANPAGES1=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1
MANPAGES5=		jail.conf.5

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP
BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		fail2ban

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_VARS.paths+=	VARBASE
SUBST_FILES.paths=	${WRKSRC}/bin/fail2ban-client
SUBST_FILES.paths+=	${WRKSRC}/fail2ban/client/configreader.py
SUBST_FILES.paths+=	${WRKSRC}/fail2ban/tests/utils.py
SUBST_FILES.paths+=	${WRKSRC}/man/fail2ban-client.1
SUBST_FILES.paths+=	${WRKSRC}/man/fail2ban-client.h2m
SUBST_FILES.paths+=	${WRKSRC}/setup.py
SUBST_FILES.paths+=	${WRKSRC}/config/fail2ban.conf
SUBST_FILES.paths+=	${WRKSRC}/config/jail.conf
SUBST_FILES.paths+=	${WRKSRC}/config/paths-pkgsrc.conf
SUBST_SED.paths=	-e 's,/etc,${PREFIX}/etc,g'
SUBST_SED.paths+=	-e 's,/var/lib,${VARBASE}/db,g'
SUBST_SED.paths+=	-e 's,/var,${VARBASE},g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,paths-debian.conf,paths-pkgsrc.conf,g'

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-install
SUBST_MESSAGE.install=	correcting installation path
SUBST_FILES.install=	${WRKSRC}/setup.py
SUBST_SED.install=	-e 's,${PREFIX}/etc/fail2ban,${EGDIR},g'

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		ostype
SUBST_STAGE.ostype=	post-configure
SUBST_MESSAGE.ostype=	Adjusting OS type
SUBST_FILES.ostype=	${WRKSRC}/config/paths-pkgsrc.conf
.if ${OPSYS} == "NetBSD"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-netbsd.conf,g"
.elif ${OPSYS} == "Darwin"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-osx.conf,g"
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
SUBST_SED.ostype=	-e "s,\#before = paths-distro.conf,before = paths-freebsd.conf,g"
.endif


post-extract:
	${CP} ${FILESDIR}/paths-netbsd.conf ${WRKSRC}/config/paths-netbsd.conf
	${CP} ${FILESDIR}/paths-pkgsrc.conf ${WRKSRC}/config/paths-pkgsrc.conf

post-build:
	        cd ${WRKSRC}/doc/ && make text

post-install:
.for manfile1 in ${MANPAGES1}
	${INSTALL_MAN} ${WRKSRC}/man/${manfile1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for manfile5 in ${MANPAGES5}
	${INSTALL_MAN} ${WRKSRC}/man/${manfile5} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
.endfor
.for i in ${TXTDOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/build/text/${i} ${DESTDIR}${DOCDIR}/
.endfor

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
