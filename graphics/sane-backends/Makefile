# $NetBSD: Makefile,v 1.67 2016/04/09 14:19:25 richard Exp $

PKGREVISION=	4
.include "Makefile.common"
COMMENT=	API for access to scanners, digital cameras, frame grabbers, etc

DISTNAME=	sane-backends-${SANE_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

# lib/Makefile.in builds .o files and then .a, but rules for shlibs,
# while apparently independent, cause libtool to create .o again,
# making it possible for the ar step of the .a build to fail to find
# the .o
MAKE_JOBS_SAFE=		NO

USE_TOOLS+=		msgfmt msgmerge pkg-config
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-gphoto2=no
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/sane-${SANE_VERSION}
CONFIGURE_ARGS+=	--without-snmp
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		mustek pint sm3600

.if (${OPSYS} == "SunOS") || (${OPSYS} == "Linux") || (${OPSYS} == "DragonFly") || (${OPSYS} == "FreeBSD")
PLIST.sm3600=		yes
.elif (${OPSYS} == "Darwin")
PLIST.mustek=		yes
PLIST.sm3600=		yes
.else
PLIST.pint=		yes
PLIST.sm3600=		yes
.endif

OWN_DIRS+=	${PKG_SYSCONFDIR}/sane.d
EGDIR=		${PREFIX}/share/examples/sane
.for f in abaton.conf agfafocus.conf apple.conf artec.conf \
artec_eplus48u.conf avision.conf bh.conf canon.conf canon630u.conf \
canon_dr.conf cardscan.conf coolscan.conf coolscan2.conf coolscan3.conf \
dc210.conf dc240.conf dc25.conf dell1600n_net.conf dll.conf dmc.conf \
epjitsu.conf epson.conf epson2.conf epsonds.conf fujitsu.conf \
genesys.conf gt68xx.conf hp.conf hp3900.conf \
hp4200.conf hp5400.conf hs2p.conf ibm.conf kodak.conf leo.conf lexmark.conf \
ma1509.conf matsushita.conf \
microtek.conf microtek2.conf mustek.conf mustek_usb.conf \
nec.conf net.conf \
p5.conf pie.conf pieusb.conf pixma.conf plustek.conf plustek_pp.conf \
ricoh.conf rts8891.conf \
s9036.conf saned.conf sceptre.conf sharp.conf sm3840.conf snapscan.conf \
sp15c.conf st400.conf stv680.conf \
tamarack.conf teco1.conf teco2.conf teco3.conf \
test.conf u12.conf umax.conf umax1220u.conf umax_pp.conf xerox_mfp.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.endfor

.if (${OPSYS} == "Linux")
.  for f in qcam.conf v4l.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/sane.d/${f}
.  endfor
.endif

.include "options.mk"
.include "../../devel/libusb1/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libusb_1_0
.if (${OPSYS} == "Linux")
.include "../../graphics/libv4l/buildlink3.mk"
.endif
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
