# $NetBSD: Makefile,v 1.16 2017/07/11 11:12:22 jaapb Exp $
#

VERSION=	4.1.0
GITHUB_PROJECT=	tyxml
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/tyxml/
COMMENT=	OCaml XML typing library
LICENSE=	gnu-lgpl-v2.1 # with openssl exemption

CONFLICTS+=	ocsigen<2.0

CONFIGURE_ARGS+=	--enable-syntax --bindir ${DESTDIR}${PREFIX}/bin

USE_TOOLS=	gmake
OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-markup/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
#.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
