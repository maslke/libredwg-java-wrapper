#include <jni.h>
#include <stdio.h>
#include "arc.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setCenterNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    BITCODE_3BD center = {.x = x, .y = y, .z = z};
    arc_entity->center = center;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setRadiusNative(JNIEnv *env, jobject job, jlong ref, jdouble radius) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    arc_entity->radius = radius;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    arc_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setExtrusion(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    arc_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Arc_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    return (intptr_t)arc_entity->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setStartAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    arc_entity->start_angle = angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setEndAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    arc_entity->end_angle = angle;
}


JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getCenterNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, arc_entity->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, arc_entity->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, arc_entity->center.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getRadiusNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    return arc_entity->radius;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    return arc_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, arc_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, arc_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, arc_entity->extrusion.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getStartAngleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    return arc_entity->start_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getEndAngleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    return arc_entity->end_angle;
}
