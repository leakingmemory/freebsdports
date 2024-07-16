--- include/fhir/bundle.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/bundle.h
@@ -15,7 +15,7 @@ class FhirBundle : public Fhir { (public)
     std::string type{};
     int total{0};
 public:
-    constexpr FhirBundle() : Fhir("Bundle") {}
+    FhirBundle() : Fhir("Bundle") {}
     void SetType(const std::string &type) {
         this->type = type;
     }
