# $NetBSD: Makefile,v 1.10 2014/05/29 23:38:06 wiz Exp $

DISTNAME=	HTML-StripScripts-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-StripScripts/
COMMENT=	Perl5 module to strip scripting constructs out of HTML
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/HTML/StripScripts/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
