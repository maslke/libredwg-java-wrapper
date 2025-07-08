#include <jni.h>
#include <stdio.h>
#include "point.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_SetThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    point_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_SetExtrusion(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    BITCODE_BE extrusion = {.x = x, .y = y, .z = z};
    point_entity->extrusion = extrusion;
}
