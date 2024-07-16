--- include/fhir/bundleentry.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/bundleentry.h
@@ -16,7 +16,7 @@ class FhirBundleEntry : public FhirObject { (public)
     std::string fullUrl;
     std::shared_ptr<Fhir> resource;
 public:
-    constexpr FhirBundleEntry() : fullUrl(), resource() {}
+    FhirBundleEntry() : fullUrl(), resource() {}
     template <FhirSubclass T> FhirBundleEntry(const std::string &url, const std::shared_ptr<T> &entry)
         : fullUrl(url), resource(entry) {}
     template <FhirSubclass T> FhirBundleEntry(std::string &&url, const std::shared_ptr<T> &entry)
