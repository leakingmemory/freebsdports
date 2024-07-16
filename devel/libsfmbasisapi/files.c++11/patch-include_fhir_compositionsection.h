--- include/fhir/compositionsection.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/compositionsection.h
@@ -16,7 +16,7 @@ class FhirCompositionSection : public FhirObject { (pu
     std::string textStatus{};
     std::string textXhtml{};
 public:
-    constexpr FhirCompositionSection() {}
+    FhirCompositionSection() {}
 
     void SetCode(const FhirCodeableConcept &code) { this->code = code; }
     void SetEmptyReason(const FhirCodeableConcept &emptyReason) { this->emptyReason = emptyReason; }
@@ -37,4 +37,4 @@ class FhirCompositionSection : public FhirObject { (pu
     static FhirCompositionSection Parse(const web::json::value &obj);
 };
 
-#endif //SFMBASISFAKER_COMPOSITIONSECTION_H
\ No newline at end of file
+#endif //SFMBASISFAKER_COMPOSITIONSECTION_H
