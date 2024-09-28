PORTNAME=	libjjwtid
DISTVERSION=	0.0.9
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	leakingmemory

LICENSE=	LGPL21

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	Library for JWTs and signing.
WWW=		https://github.com/leakingmemory/libjjwtid/

USES=		cmake

BUILD_DEPENDS=	/usr/local/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libcpprest.so:devel/cpprestsdk

#USE_GCC=	11
#CFLAGS+=	-I/usr/local/include

.include <bsd.port.mk>
