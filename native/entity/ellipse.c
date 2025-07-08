#include <jni.h>
#include <stdio.h>
#include "ellipse.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
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

