# $NetBSD: Makefile,v 1.7 2014/12/12 04:56:43 mef Exp $

DISTNAME=	Dancer-Plugin-DBIC-0.2100
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dancer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dancer-Plugin-DBIC/
COMMENT=	DBIx::Class interface for Dancer applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Dancer>=1.3098:../../www/p5-Dancer

# recommended ...
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.07002:../../databases/p5-DBIx-Class-Schema-Loader

PERL5_PACKLIST=		auto/Dancer/Plugin/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
