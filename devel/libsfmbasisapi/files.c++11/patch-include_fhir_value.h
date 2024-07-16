--- include/fhir/value.h.orig	2023-12-18 21:15:04 UTC
+++ include/fhir/value.h
@@ -11,9 +11,9 @@ class FhirString : public FhirValue { (public)
 private:
     std::string value;
 public:
-    constexpr FhirString() noexcept : value() {}
-    explicit constexpr FhirString(const std::string &value) noexcept : value(value) {}
-    explicit constexpr FhirString(std::string &&value) noexcept : value(std::move(value)) {}
+    FhirString() noexcept : value() {}
+    explicit FhirString(const std::string &value) noexcept : value(value) {}
+    explicit FhirString(std::string &&value) noexcept : value(std::move(value)) {}
     static std::string PropertyName() {
         return "valueString";
     }
@@ -31,10 +31,10 @@ class FhirCoding : public FhirObject { (public)
     std::string code;
     std::string display;
 public:
-    constexpr FhirCoding() : system(), code(), display() {}
-    constexpr FhirCoding(const std::string &system, const std::string &code, const std::string &display) :
+    FhirCoding() : system(), code(), display() {}
+    FhirCoding(const std::string &system, const std::string &code, const std::string &display) :
         system(system), code(code), display(display) {}
-    constexpr FhirCoding(std::string &&system, std::string &&code, std::string &&display) :
+    FhirCoding(std::string &&system, std::string &&code, std::string &&display) :
             system(std::move(system)), code(std::move(code)), display(std::move(display)) {}
     web::json::value ToJson() const override;
     static FhirCoding Parse(const web::json::value &obj);
@@ -54,15 +54,15 @@ class FhirCodeableConcept : public FhirObject { (publi
     std::vector<FhirCoding> coding;
     std::string text;
 public:
-    constexpr FhirCodeableConcept() : coding(), text() {}
-    constexpr explicit FhirCodeableConcept(const std::vector<FhirCoding> &coding) : coding(coding), text() {}
-    constexpr explicit FhirCodeableConcept(std::vector<FhirCoding> &&coding) : coding(std::move(coding)), text() {}
-    constexpr explicit FhirCodeableConcept(std::vector<FhirCoding> &&coding, std::string &&text) : coding(std::move(coding)), text(std::move(text)) {}
-    constexpr explicit FhirCodeableConcept(const std::string &system, const std::string &code, const std::string &name)
+    FhirCodeableConcept() : coding(), text() {}
+    explicit FhirCodeableConcept(const std::vector<FhirCoding> &coding) : coding(coding), text() {}
+    explicit FhirCodeableConcept(std::vector<FhirCoding> &&coding) : coding(std::move(coding)), text() {}
+    explicit FhirCodeableConcept(std::vector<FhirCoding> &&coding, std::string &&text) : coding(std::move(coding)), text(std::move(text)) {}
+    explicit FhirCodeableConcept(const std::string &system, const std::string &code, const std::string &name)
     : coding({{system, code, name}}), text() {}
-    constexpr explicit FhirCodeableConcept(std::string &&system, std::string &&code, std::string &&name)
+    explicit FhirCodeableConcept(std::string &&system, std::string &&code, std::string &&name)
             : coding({{std::move(system), std::move(code), std::move(name)}}), text() {}
-    constexpr explicit FhirCodeableConcept(const std::string &text) : coding(), text(text) {}
+    explicit FhirCodeableConcept(const std::string &text) : coding(), text(text) {}
     [[nodiscard]] web::json::value ToJson() const override;
     static FhirCodeableConcept Parse(const web::json::value &obj);
     [[nodiscard]] std::vector<FhirCoding> GetCoding() const {
@@ -142,10 +142,10 @@ class FhirReference : public FhirObject { (public)
     std::string type;
     std::string display;
 public:
-    constexpr FhirReference() : reference(), type(), display() {}
-    constexpr FhirReference(const std::string &reference, const std::string &type, const std::string &display)
+    FhirReference() : reference(), type(), display() {}
+    FhirReference(const std::string &reference, const std::string &type, const std::string &display)
             : reference(reference), type(type), display(display) {}
-    constexpr FhirReference(std::string &&reference, std::string &&type, std::string &&display)
+    FhirReference(std::string &&reference, std::string &&type, std::string &&display)
             : reference(std::move(reference)), type(std::move(type)), display(std::move(display)) {}
 
     [[nodiscard]] std::string GetReference() const {
@@ -172,22 +172,22 @@ class FhirIdentifier : public FhirObject { (public)
     std::string system;
     std::string value;
 public:
-    constexpr FhirIdentifier() : type(), use(), system(), value() {}
-    constexpr FhirIdentifier(const std::string &use, const std::string &value)
+    FhirIdentifier() : type(), use(), system(), value() {}
+    FhirIdentifier(const std::string &use, const std::string &value)
             : type(), use(use), system(), value(value) {}
-    constexpr FhirIdentifier(std::string &&use, std::string &&value)
+    FhirIdentifier(std::string &&use, std::string &&value)
             : type(), use(std::move(use)), system(), value(std::move(value)) {}
-    constexpr FhirIdentifier(const std::string &use, const std::string &system, const std::string &value)
+    FhirIdentifier(const std::string &use, const std::string &system, const std::string &value)
             : type(), use(use), system(system), value(value) {}
-    constexpr FhirIdentifier(std::string &&use, std::string &&system, std::string &&value)
+    FhirIdentifier(std::string &&use, std::string &&system, std::string &&value)
             : type(), use(use), system(system), value(value) {}
-    constexpr FhirIdentifier(const FhirCodeableConcept &type, const std::string &use, const std::string &value)
+    FhirIdentifier(const FhirCodeableConcept &type, const std::string &use, const std::string &value)
         : type(type), use(use), system(), value(value) {}
-    constexpr FhirIdentifier(FhirCodeableConcept &&type, std::string &&use, std::string &&value)
+    FhirIdentifier(FhirCodeableConcept &&type, std::string &&use, std::string &&value)
         : type(std::move(type)), use(std::move(use)), system(), value(std::move(value)) {}
-    constexpr FhirIdentifier(const FhirCodeableConcept &type, const std::string &use, const std::string &system, const std::string &value)
+    FhirIdentifier(const FhirCodeableConcept &type, const std::string &use, const std::string &system, const std::string &value)
             : type(type), use(use), system(system), value(value) {}
-    constexpr FhirIdentifier(FhirCodeableConcept &&type, std::string &&use, std::string &&system, std::string &&value)
+    FhirIdentifier(FhirCodeableConcept &&type, std::string &&use, std::string &&system, std::string &&value)
             : type(std::move(type)), use(std::move(use)), system(std::move(system)), value(std::move(value)) {}
     [[nodiscard]] std::string GetUse() const {
         return use;
