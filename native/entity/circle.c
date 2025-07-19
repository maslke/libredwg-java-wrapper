#include <jni.h>
#include <stdio.h>
#include "circle.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setCenterNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    BITCODE_3BD center = {.x = x, .y = y, .z = z};
    circle_entity->center = center;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setRadiusNative(JNIEnv *env, jobject job, jlong ref, jdouble radius) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    circle_entity->radius = radius;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    circle_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setExtrusionNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    circle_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Circle_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return (intptr_t)circle_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Circle_getCenterNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, circle_entity->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, circle_entity->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, circle_entity->center.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Circle_getRadiusNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return circle_entity->radius;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Circle_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return circle_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Circle_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, circle_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, circle_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, circle_entity->extrusion.z);
    return pointObj;
}
