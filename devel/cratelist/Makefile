PORTNAME=	cratelist
DISTVERSION=	0.1.0
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	leakingmemory
GH_TAGNAME=	v0.1.0

LICENSE=	MIT

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	List info about dependencies (cargo)
WWW=		https://github.com/leakingmemory/cratelist/

USES=		cargo

OPTIONS_DEFINE= DOCS
PORTDOCS=	README.md SECURITY.md

CARGO_INSTALL=	no

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -m 755 ${WRKDIR}/target/release/cratelist ${STAGEDIR}${PREFIX}/bin


post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cratelist

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
