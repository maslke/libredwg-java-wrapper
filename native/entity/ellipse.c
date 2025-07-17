#include <jni.h>
#include <stdio.h>
#include "ellipse.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setCenterNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    BITCODE_3BD center = {.x = x, .y = y, .z = z};
    ellipse->center = center;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setMajorAxisNative(JNIEnv *env, jobject job, jlong ref, jdouble major_axis) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    BITCODE_3BD sm_axis = {.x = major_axis, .y = major_axis, .z = 0};
    sm_axis.z = ellipse->center.z;
    ellipse->sm_axis = sm_axis;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setAxisRatioNative(JNIEnv *env, jobject job, jlong ref, jdouble ratio) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    ellipse->axis_ratio = ratio;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setExtrusionNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    ellipse->extrusion = extrusion;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setStartAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    ellipse->start_angle = angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setEndAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    ellipse->end_angle = angle;
}


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    return (jlong)(intptr_t)ellipse->parent;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getStartAngleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    return ellipse->start_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getEndAngleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    return ellipse->end_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getMajorAxisNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    return ellipse->sm_axis.x;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getAxisRatioNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    return ellipse->axis_ratio;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getCenterNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, ellipse->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, ellipse->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, ellipse->center.z);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, vectorClass, "<init>", "()V");
    jobject vectorObj = (*env)->NewObject(env, vectorClass, constructor);

    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    (*env)->SetDoubleField(env, vectorObj, xField, ellipse->extrusion.x);
    (*env)->SetDoubleField(env, vectorObj, yField, ellipse->extrusion.y);
    (*env)->SetDoubleField(env, vectorObj, zField, ellipse->extrusion.z);
    return vectorObj;
}

