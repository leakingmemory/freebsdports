PORTNAME=	sfmbasisfaker
DISTVERSION=	0.1.3
CATEGORIES=	www
USE_GITHUB=	yes
GH_ACCOUNT=	leakingmemory

LICENSE=	AGPLv3

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	Faker API that mimics the SFM basisapiet
WWW=		https://github.com/leakingmemory/libsfmbasisapi/

USES=		cmake ssl

LIB_DEPENDS=	libcpprest.so:devel/cpprestsdk libsfmbasisapi.so:devel/libsfmbasisapi libjjwtid.so:devel/libjjwtid

CFLAGS+=	-I/usr/local/include

.include <bsd.port.mk>
