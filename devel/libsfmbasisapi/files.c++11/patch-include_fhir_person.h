--- include/fhir/person.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/person.h
@@ -17,8 +17,8 @@ class FhirPerson : public Fhir { (public)
     std::string birthDate{};
     bool active{false};
 public:
-    constexpr FhirPerson() : Fhir() {}
-    constexpr FhirPerson(const std::string &resourceType) : Fhir(resourceType) {}
+    FhirPerson() : Fhir() {}
+    FhirPerson(const std::string &resourceType) : Fhir(resourceType) {}
     [[nodiscard]] std::vector<FhirIdentifier> GetIdentifiers() const { return identifiers; }
     [[nodiscard]] std::vector<FhirName> GetName() const { return name; }
     [[nodiscard]] std::vector<FhirAddress> GetAddress() const { return address; }
@@ -39,13 +39,13 @@ class FhirPatient : public FhirPerson { (public)
 
 class FhirPatient : public FhirPerson {
 public:
-    constexpr FhirPatient() : FhirPerson("Patient") {}
+    FhirPatient() : FhirPerson("Patient") {}
     FhirPatient(const FhirPerson &person) : FhirPerson(person) {}
 };
 
 class FhirPractitioner : public FhirPerson {
 public:
-    constexpr FhirPractitioner() : FhirPerson("Practitioner") {}
+    FhirPractitioner() : FhirPerson("Practitioner") {}
     FhirPractitioner(const FhirPerson &person) : FhirPerson(person) {}
 };
 
