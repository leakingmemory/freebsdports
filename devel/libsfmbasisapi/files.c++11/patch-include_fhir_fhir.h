--- include/fhir/fhir.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/fhir.h
@@ -59,9 +59,9 @@ class Fhir : public FhirExtendable { (public)
 protected:
     bool ParseInline(const web::json::value &json);
 public:
-    constexpr Fhir() : resourceType() {}
-    constexpr explicit Fhir(const std::string &resourceType) : resourceType(resourceType) {}
-    constexpr explicit Fhir(std::string &&resourceType) : resourceType(std::move(resourceType)) {}
+    Fhir() : resourceType() {}
+    explicit Fhir(const std::string &resourceType) : resourceType(resourceType) {}
+    explicit Fhir(std::string &&resourceType) : resourceType(std::move(resourceType)) {}
     web::json::value ToJson() const;
     static std::shared_ptr<Fhir> Parse(const web::json::value &obj);
     virtual std::string GetDisplay() const;
