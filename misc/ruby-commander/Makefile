# $NetBSD: Makefile,v 1.10 2015/02/04 15:07:02 taca Exp $

DISTNAME=	commander-4.1.6
CATEGORIES=	misc

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	The complete solution for Ruby command-line executables
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.6.11<1.7:../../devel/ruby-highline

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
