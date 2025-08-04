PORTNAME=	vtun-ng
DISTVERSION=	3.0.18
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

USES=		ssl cargo

OPTIONS_DEFINE= DOCS
PORTDOCS=	ChangeLog Credits FAQ README README.Setup \
         	README.Shaper TODO

CARGO_CRATES= \
        adler2-2.0.1 \
        beef-0.5.2 \
        bitflags-2.9.1 \
        block-padding-0.3.3 \
        blowfish-0.9.1 \
        byteorder-1.5.0 \
        cc-1.2.29 \
        cfg-if-1.0.1 \
        cipher-0.4.4 \
        crc32fast-1.5.0 \
        crypto-common-0.1.6 \
        deranged-0.4.0 \
        dns-lookup-2.0.4 \
        ecb-0.1.2 \
        errno-0.3.13 \
        flate2-1.1.2 \
        fnv-1.0.7 \
        foreign-types-0.3.2 \
        foreign-types-shared-0.1.1 \
        generic-array-0.14.7 \
        getopts-0.2.23 \
        inout-0.1.4 \
        itoa-1.0.15 \
        lazy_static-1.5.0 \
        libc-0.2.174 \
        logos-0.15.0 \
        logos-codegen-0.15.0 \
        logos-derive-0.15.0 \
        md5-0.8.0 \
        miniz_oxide-0.8.9 \
        num-conv-0.1.0 \
        once_cell-1.21.3 \
        openssl-0.10.73 \
        openssl-macros-0.1.1 \
        openssl-sys-0.9.109 \
        pkg-config-0.3.32 \
        powerfmt-0.2.0 \
        proc-macro2-1.0.95 \
        proctitle-0.1.1 \
        quote-1.0.40 \
        regex-syntax-0.8.5 \
        rust-lzo-0.6.2 \
        rustc_version-0.4.1 \
        semver-1.0.26 \
        serde-1.0.219 \
        serde_derive-1.0.219 \
        shlex-1.3.0 \
        signal-hook-0.3.18 \
        signal-hook-registry-1.4.5 \
        socket2-0.5.10 \
        syn-2.0.104 \
        time-0.3.41 \
        time-core-0.1.4 \
        time-macros-0.2.22 \
        typenum-1.18.0 \
        unicode-ident-1.0.18 \
        unicode-width-0.2.1 \
        vcpkg-0.2.15 \
        version_check-0.9.5 \
        winapi-0.3.9 \
        winapi-i686-pc-windows-gnu-0.4.0 \
        winapi-x86_64-pc-windows-gnu-0.4.0 \
        windows-sys-0.48.0 \
        windows-sys-0.52.0 \
        windows-sys-0.60.2 \
        windows-targets-0.48.5 \
        windows-targets-0.52.6 \
        windows-targets-0.53.2 \
        windows_aarch64_gnullvm-0.48.5 \
        windows_aarch64_gnullvm-0.52.6 \
        windows_aarch64_gnullvm-0.53.0 \
        windows_aarch64_msvc-0.48.5 \
        windows_aarch64_msvc-0.52.6 \
        windows_aarch64_msvc-0.53.0 \
        windows_i686_gnu-0.48.5 \
        windows_i686_gnu-0.52.6 \
        windows_i686_gnu-0.53.0 \
        windows_i686_gnullvm-0.52.6 \
        windows_i686_gnullvm-0.53.0 \
        windows_i686_msvc-0.48.5 \
        windows_i686_msvc-0.52.6 \
        windows_i686_msvc-0.53.0 \
        windows_x86_64_gnu-0.48.5 \
        windows_x86_64_gnu-0.52.6 \
        windows_x86_64_gnu-0.53.0 \
        windows_x86_64_gnullvm-0.48.5 \
        windows_x86_64_gnullvm-0.52.6 \
        windows_x86_64_gnullvm-0.53.0 \
        windows_x86_64_msvc-0.48.5 \
        windows_x86_64_msvc-0.52.6 \
        windows_x86_64_msvc-0.53.0

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
