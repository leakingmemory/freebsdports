--- nhnfhir/KjRfErrorCode.cpp.orig	2023-12-18 21:15:04 UTC
+++ nhnfhir/KjRfErrorCode.cpp
@@ -4,7 +4,7 @@
 
 #include <nhnfhir/KjRfErrorCode.h>
 
-constexpr std::vector<FhirCoding> Coding(std::string &&system, std::string &&code, std::string &&name) {
+static std::vector<FhirCoding> Coding(std::string &&system, std::string &&code, std::string &&name) {
     std::vector<FhirCoding> codings{};
     codings.emplace_back(system, code, name);
     return codings;
