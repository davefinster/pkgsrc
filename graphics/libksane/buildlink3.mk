# $NetBSD: buildlink3.mk,v 1.20 2014/11/07 19:39:25 adam Exp $

BUILDLINK_TREE+=	libksane

.if !defined(LIBKSANE_BUILDLINK3_MK)
LIBKSANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksane+=	libksane>=4.8.0
BUILDLINK_ABI_DEPENDS.libksane?=	libksane>=4.11.5nb5
BUILDLINK_PKGSRCDIR.libksane?=	../../graphics/libksane

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKSANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksane
