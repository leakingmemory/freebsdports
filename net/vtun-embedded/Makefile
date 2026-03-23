PORTNAME=	vtun-embedded
PORTVERSION=	3.1.0
CATEGORIES=	net
MASTER_SITES=	 \
		https://github.com/leakingmemory/vtun-embedded/releases/download/v${DISTVERSION}/

MAINTAINER=	sigsegv@radiotube.org
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping
WWW=		https://github.com/leakingmemory/vtun-embedded/

LICENSE=	GPLv2

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		autoreconf localbase ssl bison
USE_RC_SUBR=	vtunclient-embedded vtunemd
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--localstatedir=/var \
		--with-lzo-headers=${LOCALBASE}/include/lzo \
		--with-lzo-lib=${LOCALBASE}/lib \
		--with-ssl-headers=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB}
CONFIGURE_ENV=	YACC=${YACC}

ALL_TARGET=	vtunemd

CFLAGS+=	-ansi -Wno-pointer-sign

PORTDOCS=	ChangeLog Credits FAQ README README.LZO README.Setup \
		README.Shaper TODO

OPTIONS_DEFINE=	DOCS

# Extended mode patches, obtained from
# http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
# are now dynamically enabled using the -e option.

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$\(SSL_HDR_DIR\)|$$\1 $$\1/openssl|g' \
		-e 's|$$\(BLOWFISH_HDR_DIR\)|$$\1 $$SSL_HDR_DIR/openssl|g' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtunemd
	${INSTALL_DATA} ${WRKSRC}/vtunemd.conf ${STAGEDIR}${PREFIX}/etc/vtunemd.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man8/vtunemd.8 ${STAGEDIR}${PREFIX}/share/man/man1/vtunem.1

post-install-DOCS-on:
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
