# $NetBSD: Makefile,v 1.8 2017/07/27 11:16:10 markd Exp $

DISTNAME=	collection-langchinese
PKGNAME=	texlive-${DISTNAME}-2017pre2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	42675

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Chinese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

DEPENDS+=	tex-arphic-[0-9]*:../../fonts/tex-arphic
DEPENDS+=	tex-arphic-ttf-[0-9]*:../../fonts/tex-arphic-ttf
# asymptote-by-example-zh-cn is documentation only
# asymptote-faq-zh-cn is documentation only
# asymptote-manual-zh-cn is documentation only
DEPENDS+=	tex-cmsd-[0-9]*:../../fonts/tex-cmsd
# depend ctex
# ctex-faq is documentation only
# depend fandol
DEPENDS+=	tex-hyphen-chinese-[0-9]*:../../print/tex-hyphen-chinese
# impatient-cn is documentation only
# latex-notes-zh-cn is documentation only
# lshort-chinese is documentation only
# texlive-zh-cn is documentation only
# texproposal is documentation only
# depend xpinyin
# depend zhmetrics
# depend zhmetrics-uptex
# depend zhnumber
# depend zhspacing

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
