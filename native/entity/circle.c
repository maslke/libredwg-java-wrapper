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
#include "cjson/cJSON.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setCenterNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    BITCODE_3BD center = {.x = x, .y = y, .z = z};
    circle_entity->center = center;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setRadiusNative(JNIEnv *env, jobject job, jlong ref, jdouble radius) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    circle_entity->radius = radius;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    circle_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setExtrusion(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    circle_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Circle_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    return (intptr_t)circle_entity->parent;
}
