#include <jni.h>
#include <stdio.h>
#include <dwg.h>
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersion
  (JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "0.0.1");
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_create(JNIEnv *env, jclass clazz) {
    Dwg_Data *dwg_data = dwg_new_Document(R_2000, 0, 0);
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_open(JNIEnv *env, jclass clazz, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data *) malloc(sizeof(Dwg_Data));
    const char *file = (*env)->GetStringUTFChars(env, filename, NULL);
    memset(dwg_data, 0, sizeof(Dwg_Data));
    dwg_read_file(file, dwg_data);
    (*env)->ReleaseStringUTFChars(env, filename, file);
    return (jlong)(intptr_t)dwg_data;
}

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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_SetStart(JNIEnv *env, jobject obj, jlong ref, jobject start) {
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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEnd(JNIEnv *env, jobject obj, jlong ref, jobject end) {
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

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addPointNative(JNIEnv *env, jobject obj, jlong ref,
jdouble x, jdouble y, jdouble z
) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    dwg_point_3d pt1 = { .x = x, .y = y, .z = y };
    Dwg_Entity_POINT *point_entity =  dwg_add_POINT(hdr, &pt1);
    return (jlong)(intptr_t)point_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addLineNative(JNIEnv *env, jobject obj, jlong ref,
jobject start, jobject end) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble start_x = (*env)->GetDoubleField(env, start, fidX);
    jdouble start_y = (*env)->GetDoubleField(env, start, fidY);
    jdouble start_z = (*env)->GetDoubleField(env, start, fidZ);

    dwg_point_3d start_point = {.x = start_x, .y = start_y, .z = start_z};

    jdouble end_x = (*env)->GetDoubleField(env, end, fidX);
    jdouble end_y = (*env)->GetDoubleField(env, end, fidY);
    jdouble end_z = (*env)->GetDoubleField(env, end, fidZ);

    dwg_point_3d end_point = {.x = end_x, .y = end_y, .z = end_z};

    Dwg_Entity_LINE *line_entity = dwg_add_LINE(hdr, &start_point, &end_point);

    return (jlong)(intptr_t)line_entity;
}

