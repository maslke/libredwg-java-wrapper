#include <jni.h>
#include <stdio.h>
#include "line.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStartNative(JNIEnv *env, jobject obj, jlong ref, jobject start) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    jclass start_class = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, start_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, start_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, start_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, start, fidX);
    jdouble y = (*env)->GetDoubleField(env, start, fidY);
    jdouble z = (*env)->GetDoubleField(env, start, fidZ);
    BITCODE_3BD s = {.x = x, .y = y, .z = z};
    line_entity->start = s;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEndNative(JNIEnv *env, jobject obj, jlong ref, jobject end) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    jclass end_class = (*env)->GetObjectClass(env, end);
    jfieldID fidX = (*env)->GetFieldID(env, end_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, end_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, end_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, end, fidX);
    jdouble y = (*env)->GetDoubleField(env, end, fidY);
    jdouble z = (*env)->GetDoubleField(env, end, fidZ);
    BITCODE_3BD e = {.x = x, .y = y, .z = z};
    line_entity->end = e;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    line_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setExtrusionNative(JNIEnv *env, jobject, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    line_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    return (intptr_t)line_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getStartNative(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
   if (pointCls == NULL) {
       return NULL;
   }
   jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
   jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

   jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
   jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");

   (*env)->SetDoubleField(env, pointObj, xField, line_entity->start.x);
   (*env)->SetDoubleField(env, pointObj, yField, line_entity->start.y);
   return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getEndNative(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
   if (pointCls == NULL) {
       return NULL;
   }
   jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
   jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

   jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
   jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");

   (*env)->SetDoubleField(env, pointObj, xField, line_entity->end.x);
   (*env)->SetDoubleField(env, pointObj, yField, line_entity->end.y);
   return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
   if (pointCls == NULL) {
       return NULL;
   }
   jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
   jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

   jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
   jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
   jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
   (*env)->SetDoubleField(env, pointObj, xField, line_entity->extrusion.x);
   (*env)->SetDoubleField(env, pointObj, yField, line_entity->extrusion.y);
   (*env)->SetDoubleField(env, pointObj, zField, line_entity->extrusion.z);
   return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Line_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    return line_entity->thickness;
}
