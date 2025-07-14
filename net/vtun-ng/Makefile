PORTNAME=	vtun-ng
DISTVERSION=	3.0.6
CATEGORIES=	net
USE_GITHUB=	nodefault
GH_ACCOUNT=	leakingmemory
DISTFILES=	vtun-ng-${DISTVERSION}.tar.gz
MASTER_SITES=	\
	https://github.com/leakingmemory/vtun-ng/releases/download/v${DISTVERSION}/

LICENSE=	GPLv2

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	Simple VPN-type tunneling service
WWW=		https://github.com/leakingmemory/vtun-ng/

USES=		autoreconf localbase ssl bison cargo gmake

LIB_DEPENDS=	liblzo2.so:archivers/lzo2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--localstatedir=/var \
               	--with-lzo-headers=${LOCALBASE}/include/lzo \
               	--with-lzo-lib=${LOCALBASE}/lib \
               	--with-ssl-headers=${OPENSSLINC} \
                --with-ssl-lib=${OPENSSLLIB}
CONFIGURE_ENV=	YACC=${YACC}

ALL_TARGET=	vtund

CFLAGS+=	-ansi -Wno-pointer-sign

OPTIONS_DEFINE= DOCS
PORTDOCS=	ChangeLog Credits FAQ README README.LZO README.Setup \
         	README.Shaper TODO

CARGO_CRATES= \
	bitflags-2.9.1 \
	cc-1.2.29 \
	cfg-if-1.0.1 \
	foreign-types-0.3.2 \
	foreign-types-shared-0.1.1 \
	libc-0.2.174 \
	once_cell-1.21.3 \
	openssl-0.10.73 \
	openssl-macros-0.1.1 \
	openssl-sys-0.9.109 \
	pkg-config-0.3.32 \
	proc-macro2-1.0.95 \
	quote-1.0.40 \
	shlex-1.3.0 \
	syn-2.0.104 \
	unicode-ident-1.0.18 \
	vcpkg-0.2.15

CARGO_CARGOTOML=${WRKSRC}/rust/linkfd/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no

do-build:
	${MAKE_CMD} -C ${WRKSRC}
do-install:
	${MAKE_CMD} -C ${WRKSRC} DESTDIR=${STAGEDIR} install

# Extended mode patches, obtained from
# http://home.jp.FreeBSD.org/~simokawa/vtun-v6.html
# are now dynamically enabled using the -e option.

post-patch:
	${REINPLACE_CMD} \
	        -e 's|$$\(SSL_HDR_DIR\)|$$\1 $$\1/openssl|g' \
	        -e 's|$$\(BLOWFISH_HDR_DIR\)|$$\1 $$SSL_HDR_DIR/openssl|g' \
	        ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtunngd
	${INSTALL_DATA} ${WRKSRC}/vtunngd.conf ${STAGEDIR}${PREFIX}/etc/vtunngd.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man8/vtunngd.8 ${STAGEDIR}${PREFIX}/share/man/man1/vtunng.1

post-install-DOCS-on:
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
