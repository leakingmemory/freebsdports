PORTNAME=	vtun-ng
DISTVERSION=	3.0.19
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

USES=		cargo

OPTIONS_DEFINE= DOCS
PORTDOCS=	ChangeLog Credits FAQ README README.Setup \
         	README.Shaper TODO

CARGO_INSTALL=	no
CARGO_ENV= \
	VTUN_CONFIG_FILE=/usr/local/etc/vtunngd.conf

do-install:
	${INSTALL} -d -m 0755 ${STAGEDIR}${PREFIX}${MAN_DIR}/man8
	${INSTALL_DATA} ${WRKSRC}/vtunngd.8 ${STAGEDIR}${PREFIX}${MAN_DIR}/man8
	${INSTALL} -d -m 0755 ${STAGEDIR}${PREFIX}${MAN_DIR}/man5
	${INSTALL_DATA} ${WRKSRC}/vtunngd.conf.5 ${STAGEDIR}${PREFIX}${MAN_DIR}/man5
	ln -s vtunngd.8 ${STAGEDIR}${PREFIX}${MAN_DIR}/man8/vtunng.8
	ln -s vtunngd.8 ${STAGEDIR}${PREFIX}${MAN_DIR}/man8/vtunng.1

	${INSTALL} -d -m 0755 ${STAGEDIR}${PREFIX}/etc
	${CP} ${WRKSRC}/vtunngd.conf ${WRKDIR}/vtunngd.conf.sample
	${INSTALL} -m 0600 ${WRKDIR}/vtunngd.conf.sample ${STAGEDIR}${PREFIX}/etc

	${INSTALL} -d -m 755 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL} -m 755 ${WRKDIR}/target/release/vtunngd ${STAGEDIR}${PREFIX}/sbin


post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/vtunngd
	${INSTALL} -d -m 755 ${STAGEDIR}/var/run/vtunngd

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
