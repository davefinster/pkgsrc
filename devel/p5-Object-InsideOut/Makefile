# $NetBSD: Makefile,v 1.23 2014/05/29 23:36:09 wiz Exp $

DISTNAME=	Object-InsideOut-3.98
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-InsideOut/
COMMENT=	Perl 5 module providing comprehensive inside-out object support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.29:../../devel/p5-Exception-Class
DEPENDS+=	p5-Scalar-List-Utils>=1.23:../../devel/p5-Scalar-List-Utils

# Recommended dependencies
DEPENDS+=	p5-Want>=0.12:../../devel/p5-Want
#DEPENDS+=	{perl>=5.8.8,p5-Storable>=2.15}:../../devel/p5-Storable

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/InsideOut/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
