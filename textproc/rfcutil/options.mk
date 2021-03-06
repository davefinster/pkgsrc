# $NetBSD: options.mk,v 1.1 2009/01/04 15:37:07 hubertf Exp $

PKG_OPTIONS_VAR=			PKG_OPTIONS.rfcutil
PKG_OPTIONS_OPTIONAL_GROUPS=		rfcutil-browser
PKG_OPTIONS_GROUP.rfcutil-browser=	links lynx w3m
PKG_SUGGESTED_OPTIONS=			links

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-[0-9]*:../../www/w3m
RFCVIEWER=	w3m lynx
RFCDUMPOPT=	-dump
.endif

.if !empty(PKG_OPTIONS:Mlynx)
DEPENDS+=	lynx-[0-9]*:../../www/lynx
RFCVIEWER=	lynx w3m
RFCDUMPOPT=	-dump
.endif

.if !empty(PKG_OPTIONS:Mlinks)
DEPENDS+=	links-[0-9]*:../../www/links
RFCVIEWER=	links lynx w3m
RFCDUMPOPT=	-source
.endif
