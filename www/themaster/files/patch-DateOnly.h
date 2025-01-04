--- DateOnly.h.orig	2024-11-13 06:41:03 UTC
+++ DateOnly.h
@@ -7,6 +7,7 @@
 
 #include <cstdint>
 #include <string>
+#include <ctime>
 
 class DateOnlyInvalidException : public std::exception {
 public:
