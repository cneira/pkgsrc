# $NetBSD: Makefile,v 1.7 2017/04/06 20:00:49 fhajny Exp $

DISTNAME=	liblognorm-2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.liblognorm.com/files/download/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.liblognorm.com/
COMMENT=	Tool to normalize log data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lognorm.pc.in

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libfastjson/buildlink3.mk"
.include "../../devel/libestr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
