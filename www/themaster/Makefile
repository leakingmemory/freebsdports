PORTNAME=	themaster
DISTVERSION=	0.4.5
CATEGORIES=	www
USE_GITHUB=	yes
GH_ACCOUNT=	leakingmemory

LICENSE=	AGPLv3

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	Faker API that mimics the SFM basisapiet
WWW=		https://github.com/leakingmemory/libsfmbasisapi/

USES=		cmake ssl

BUILD_DEPENDS=	/usr/local/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libcpprest.so:devel/cpprestsdk libsfmbasisapi.so:devel/libsfmbasisapi libwx_gtk3u_core-3.2.so:x11-toolkits/wxgtk32 libjjwtid.so:devel/libjjwtid libmedfest.so:devel/libmedfest

CFLAGS+=	-I/usr/local/include

.include <bsd.port.mk>
