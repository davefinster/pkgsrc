# $NetBSD: Makefile,v 1.12 2014/10/09 14:06:26 wiz Exp $
#

DISTNAME=		Sort-Versions-1.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sort-Versions/
COMMENT=		Perl5 module for sorting of revision-like numbers

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sort/Versions/.packlist

CONFLICTS+=		p5-SortVersion-[0-9]*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
