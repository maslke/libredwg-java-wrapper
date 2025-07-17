#include <jni.h>
#include <stdio.h>
#include "point.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setXNative(JNIEnv *env, jobject obj, jlong ref, jdouble x) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    point_entity->x = x;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setYNative(JNIEnv *env, jobject obj, jlong ref, jdouble y) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    point_entity -> y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZNative(JNIEnv *env, jobject obj, jlong ref, jdouble z) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    point_entity->z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThicknessNative(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    point_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusionNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    point_entity->extrusion = extrusion;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getXNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    return point_entity->x;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getYNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    return point_entity->y;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getZNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    return point_entity->z;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    return point_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Point_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, point_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, point_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, point_entity->extrusion.z);
    return pointObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Point_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    return (jlong)(intptr_t)point_entity->parent;
}
