--- include/fhir/composition.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/composition.h
@@ -19,7 +19,7 @@ class FhirComposition : public Fhir { (public)
     std::string title{};
     std::string confidentiality{};
 public:
-    constexpr FhirComposition() : Fhir("Composition") {}
+    FhirComposition() : Fhir("Composition") {}
     [[nodiscard]] FhirIdentifier GetIdentifier() const { return identifier; }
     [[nodiscard]] FhirCodeableConcept GetType() const { return type; }
     [[nodiscard]] FhirReference GetSubject() const { return subject; }
