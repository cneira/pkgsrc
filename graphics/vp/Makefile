# $NetBSD: Makefile,v 1.21 2015/04/25 14:23:20 tnn Exp $
#

DISTNAME=		vp-1.8
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://elfga.com/~erik/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elfga.com/~erik/
COMMENT=		Image viewer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl -lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
