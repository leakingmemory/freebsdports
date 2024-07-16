--- include/fhir/fhirextendable.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/fhirextendable.h
@@ -15,7 +15,7 @@ class FhirExtendable : public FhirObject { (public)
 protected:
     bool ParseInline(const web::json::value &json);
 public:
-    constexpr FhirExtendable() {}
+    FhirExtendable() {}
     web::json::value ToJson() const;
     virtual ~FhirExtendable() = default;
     [[nodiscard]] std::vector<std::shared_ptr<FhirExtension>> GetExtensions() const {
