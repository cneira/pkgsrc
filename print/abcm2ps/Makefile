# $NetBSD: Makefile,v 1.44 2017/06/19 20:31:27 wiz Exp $

DISTNAME=	abcm2ps-8.13.11
CATEGORIES=	print
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinejf.free.fr/
COMMENT=	Converts ABC to music sheet in PostScript format
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	abcm2ps

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
