# $NetBSD: Makefile,v 1.25 2014/10/09 14:07:05 wiz Exp $

DISTNAME=	XML-NamespaceSupport-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-NamespaceSupport/
COMMENT=	Perl module to the SAX2 NamespaceSupport class
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/XML/NamespaceSupport/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

post-extract:
	${CHMOD} a-x ${WRKSRC}/lib/XML/NamespaceSupport.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
