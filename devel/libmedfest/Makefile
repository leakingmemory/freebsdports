PORTNAME=	libmedfest
DISTVERSION=	0.3.1
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	leakingmemory

LICENSE=	MIT

MAINTAINER=	sigsegv@raditoube.org
COMMENT=	Library for the medical FEST database.
WWW=		https://github.com/leakingmemory/libmedfest/

USES=		cmake pkgconfig

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
LIB_DEPENDS=	libzip.so:archivers/libzip libexpat.so:textproc/expat2

#USE_GCC=	11
#CFLAGS+=	-I/usr/local/include

.include <bsd.port.mk>
