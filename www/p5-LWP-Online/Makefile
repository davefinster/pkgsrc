# $NetBSD: Makefile,v 1.9 2014/10/09 14:07:11 wiz Exp $
#

DISTNAME=	LWP-Online-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-Online/
COMMENT=	Does your process have access to the web
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Online/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
