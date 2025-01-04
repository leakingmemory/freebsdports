--- AdvancedDosingPeriod.cpp.orig	2024-11-13 06:41:03 UTC
+++ AdvancedDosingPeriod.cpp
@@ -92,7 +92,7 @@ std::string FixedTimeAdvancedDosingPeriod::ToDosingTex
     return str.str();
 }
 
-constexpr void AddFixedDosing(FhirExtendable &extendable, double amount, std::string unit, double interval, std::string intervalUnit, bool accurate, const std::string &timerangeCode) {
+void AddFixedDosing(FhirExtendable &extendable, double amount, std::string unit, double interval, std::string intervalUnit, bool accurate, const std::string &timerangeCode) {
     auto ext = std::make_shared<FhirExtension>("repeatingdosage");
     ext->AddExtension(std::make_shared<FhirValueExtension>("amount", std::make_shared<FhirQuantityValue>(FhirQuantity(amount, unit))));
     ext->AddExtension(std::make_shared<FhirValueExtension>("interval", std::make_shared<FhirQuantityValue>(FhirQuantity(interval, intervalUnit))));
@@ -165,4 +165,4 @@ std::string ToDosingText(const std::vector<std::shared
 
 std::string ToDosingText(const std::vector<std::shared_ptr<AdvancedDosingPeriod>> &dosingPeriods) {
     return __ToDosingText(dosingPeriods);
-}
\ No newline at end of file
+}
