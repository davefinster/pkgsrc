# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:26 wiz Exp $
#

DISTNAME=		Scalar-Util-Refcount-1.0.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Scalar-Util-Refcount/
COMMENT=		Perl module to show an object's reference count

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Scalar/Util/Refcount/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
