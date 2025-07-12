#include <jni.h>
#include <stdio.h>
#include <dwg.h>
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
#include "entity/helper.h"


JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersionNative(JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "0.13.3");
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_createNative(JNIEnv *env, jclass clazz) {
    Dwg_Data *dwg_data = (Dwg_Data *) malloc(sizeof(Dwg_Data));
    memset(dwg_data, 0, sizeof(Dwg_Data));
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_Dwg_saveNative(JNIEnv *env, jobject obj, jlong ref, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    dwg_data->header.version = R_2000;
    const char *file = (*env)->GetStringUTFChars(env, filename, NULL);
    jint ret = dwg_write_file(file, dwg_data);
    (*env)->ReleaseStringUTFChars(env, filename, file);
    dwg_free(dwg_data);
    return ret;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getObjectBlockHeaderNative(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    int error = 0;
    Dwg_Object_BLOCK_HEADER *hdr = dwg_get_block_header(dwg_data, &error);
    return (jlong)(intptr_t)hdr;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_createObjectBlockHeaderNative(JNIEnv *env, jobject job, jlong ref, jstring name) {
    // TODO
    return NULL;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_openNative(JNIEnv *env, jclass clazz, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data *) malloc(sizeof(Dwg_Data));
    const char *file = (*env)->GetStringUTFChars(env, filename, NULL);
    memset(dwg_data, 0, sizeof(Dwg_Data));
    dwg_read_file(file, dwg_data);
    (*env)->ReleaseStringUTFChars(env, filename, file);
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_Dwg_setCodePageNative(JNIEnv *env, jobject job, jlong ref, jstring code_page) {
    Dwg_Data *dwg_data = (Dwg_Data *)(intptr_t)ref;
    const char *code = (*env)->GetStringUTFChars(env, code_page, NULL);
    dwg_data->header_vars.DWGCODEPAGE = strdup(code);
    (*env)->ReleaseStringUTFChars(env, code_page, code);
}


// parent entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *env, jobject job, jlong ref, jint color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->color.index = color;
    entity->color.flag = 0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->linewt = dxf_find_lweight(linewt);
}
// end


// Dwg block header
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPointNative(JNIEnv *env, jobject obj, jlong ref,
jdouble x, jdouble y, jdouble z
) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    dwg_point_3d pt1 = { .x = x, .y = y, .z = y };
    Dwg_Entity_POINT *point_entity =  dwg_add_POINT(hdr, &pt1);
    return (jlong)(intptr_t)point_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLineNative(JNIEnv *env, jobject obj, jlong ref,
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

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addTextNative(JNIEnv *env, jobject job, jlong ref, jstring text_value, jobject ins_pt, jdouble height) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char *chars = (*env)->GetStringUTFChars(env, text_value, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    jclass clazz = (*env)->GetObjectClass(env, ins_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble ins_x = (*env)->GetDoubleField(env, ins_pt, fidX);
    jdouble ins_y = (*env)->GetDoubleField(env, ins_pt, fidY);
    jdouble ins_z = (*env)->GetDoubleField(env, ins_pt, fidZ);

    dwg_point_3d insert_pt = { .x = ins_x, .y = ins_y, .z = ins_z };
    Dwg_Entity_TEXT *text_entity = dwg_add_TEXT(hdr, strdup(gbk_text), &insert_pt, height);
    return (jlong)(intptr_t)text_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircleNative(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_CIRCLE *circle_entity = dwg_add_CIRCLE(hdr, &center_pt, radius);
    return (jlong)(intptr_t)circle_entity;

}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArcNative(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius, jdouble start_angle, jdouble end_angle) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ARC *arc_entity = dwg_add_ARC(hdr, &center_pt, radius, start_angle, end_angle);
    return (jlong)(intptr_t)arc_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipseNative(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble majorAxis, jdouble axisRatio) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ELLIPSE *ellipse_entity = dwg_add_ELLIPSE(hdr, &center_pt, majorAxis, axisRatio);
    return (jlong)(intptr_t)ellipse_entity;
}
// end object block header