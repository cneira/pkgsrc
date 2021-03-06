$NetBSD: patch-cmake_plugin.cmake,v 1.1 2016/09/16 06:49:11 adam Exp $

Build with newer DTrace.

--- cmake/plugin.cmake.orig	2016-08-25 11:52:06.000000000 +0000
+++ cmake/plugin.cmake
@@ -52,7 +52,7 @@ ENDMACRO()
 MACRO(MYSQL_ADD_PLUGIN)
   MYSQL_PARSE_ARGUMENTS(ARG
     "LINK_LIBRARIES;DEPENDENCIES;MODULE_OUTPUT_NAME;STATIC_OUTPUT_NAME"
-    "STORAGE_ENGINE;STATIC_ONLY;MODULE_ONLY;MANDATORY;DEFAULT;DISABLED;NOT_FOR_EMBEDDED;RECOMPILE_FOR_EMBEDDED;TEST_ONLY"
+    "STORAGE_ENGINE;STATIC_ONLY;MODULE_ONLY;MANDATORY;DEFAULT;DISABLED;NOT_FOR_EMBEDDED;RECOMPILE_FOR_EMBEDDED;DTRACE_INSTRUMENTED;TEST_ONLY"
     ${ARGN}
   )
   
@@ -125,7 +125,9 @@ MACRO(MYSQL_ADD_PLUGIN)
     SET_TARGET_PROPERTIES(${target}
       PROPERTIES COMPILE_DEFINITIONS "MYSQL_SERVER")
 
-    DTRACE_INSTRUMENT(${target})
+    IF(ARG_DTRACE_INSTRUMENTED)
+      DTRACE_INSTRUMENT(${target})
+    ENDIF()
     ADD_DEPENDENCIES(${target} GenError ${ARG_DEPENDENCIES})
     IF(WITH_EMBEDDED_SERVER AND NOT ARG_NOT_FOR_EMBEDDED)
       # Embedded library should contain PIC code and be linkable
@@ -133,7 +135,9 @@ MACRO(MYSQL_ADD_PLUGIN)
       IF(ARG_RECOMPILE_FOR_EMBEDDED OR NOT _SKIP_PIC)
         # Recompile some plugins for embedded
         ADD_CONVENIENCE_LIBRARY(${target}_embedded ${SOURCES})
-        DTRACE_INSTRUMENT(${target}_embedded)   
+        IF(ARG_DTRACE_INSTRUMENTED)
+          DTRACE_INSTRUMENT(${target}_embedded)
+        ENDIF()
         IF(ARG_RECOMPILE_FOR_EMBEDDED)
           SET_TARGET_PROPERTIES(${target}_embedded 
             PROPERTIES COMPILE_DEFINITIONS "MYSQL_SERVER;EMBEDDED_LIBRARY")
@@ -197,7 +201,9 @@ MACRO(MYSQL_ADD_PLUGIN)
 
     ADD_VERSION_INFO(${target} MODULE SOURCES)
     ADD_LIBRARY(${target} MODULE ${SOURCES}) 
-    DTRACE_INSTRUMENT(${target})
+    IF(ARG_DTRACE_INSTRUMENTED)
+      DTRACE_INSTRUMENT(${target})
+    ENDIF()
     SET_TARGET_PROPERTIES (${target} PROPERTIES PREFIX ""
       COMPILE_DEFINITIONS "MYSQL_DYNAMIC_PLUGIN")
     TARGET_LINK_LIBRARIES (${target} mysqlservices)
