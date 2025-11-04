--- ClientAssertion.cpp.orig	2025-11-04 15:00:56 UTC
+++ ClientAssertion.cpp
@@ -9,6 +9,7 @@
 #include <jjwtid/Jwt.h>
 #include <jjwtid/Rs256.h>
 #include "Uuid.h"
+#include <ctime>
 
 ClientAssertion::ClientAssertion(const std::string &audienceUrl, const std::string &clientId, const std::string &jwk,
                                  const HelseidMultiTenantInfo &multiTenantInfo)
