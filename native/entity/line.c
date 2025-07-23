#include <jni.h>
#include <stdio.h>
#include "line.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStart(JNIEnv *env, jobject obj, jlong ref, jobject start) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return;
    }
    if (start == NULL) {
        return;
    }
    jclass start_class = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, start_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, start_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, start_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, start, fidX);
    jdouble y = (*env)->GetDoubleField(env, start, fidY);
    jdouble z = (*env)->GetDoubleField(env, start, fidZ);
    line_entity->start.x = x;
    line_entity->start.y = y;
    line_entity->start.z = z;
    (*env)->DeleteLocalRef(env, start_class);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEnd(JNIEnv *env, jobject obj, jlong ref, jobject end) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return;
    }
    if (end == NULL) {
        return;
    }
    jclass end_class = (*env)->GetObjectClass(env, end);
    jfieldID fidX = (*env)->GetFieldID(env, end_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, end_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, end_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, end, fidX);
    jdouble y = (*env)->GetDoubleField(env, end, fidY);
    jdouble z = (*env)->GetDoubleField(env, end, fidZ);
    line_entity->end.x = x;
    line_entity->end.y = y;
    line_entity->end.z = z;
    (*env)->DeleteLocalRef(env, end_class);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setThickness(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return;
    }
    line_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, extrusion, xField);
    jdouble y = (*env)->GetDoubleField(env, extrusion, yField);
    jdouble z = (*env)->GetDoubleField(env, extrusion, zField);
    line_entity->extrusion.x = x;
    line_entity->extrusion.y = y;
    line_entity->extrusion.z = z;
    (*env)->DeleteLocalRef(env, vectorClass);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return 0;
    }
    return (intptr_t)line_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getStart(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   if (line_entity == NULL) {
       return NULL;
   }
   jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
   if (pointCls == NULL) {
       return NULL;
   }
   jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
   jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

   jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
   jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
   jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");

   (*env)->SetDoubleField(env, pointObj, xField, line_entity->start.x);
   (*env)->SetDoubleField(env, pointObj, yField, line_entity->start.y);
   (*env)->SetDoubleField(env, pointObj, zField, line_entity->start.z);
   (*env)->DeleteLocalRef(env, pointCls);
   return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getEnd(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   if (line_entity == NULL) {
       return NULL;
   }
   jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
   if (pointCls == NULL) {
       return NULL;
   }
   jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
   jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

   jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
   jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
   jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");

   (*env)->SetDoubleField(env, pointObj, xField, line_entity->end.x);
   (*env)->SetDoubleField(env, pointObj, yField, line_entity->end.y);
   (*env)->SetDoubleField(env, pointObj, zField, line_entity->end.z);
   (*env)->DeleteLocalRef(env, pointCls);
   return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
   Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
   if (line_entity == NULL) {
       return NULL;
   }
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
   (*env)->DeleteLocalRef(env, pointCls);
   return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Line_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    if (line_entity == NULL) {
        return 0;
    }
    return line_entity->thickness;
}
