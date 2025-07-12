#include <jni.h>
#include <stdio.h>
#include "text.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setTextValueNative(JNIEnv *env, jobject job, jlong ref, jstring value) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    char gbk_text[200];
    const char *chars = (*env)->GetStringUTFChars(env, value, NULL);
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    text_entity->text_value = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, value, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHeightNative(JNIEnv *env, jobject job, jlong ref, jdouble height) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->height = height;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setRotationNative(JNIEnv *env, jobject job, jlong ref, jdouble rotation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setInsPtNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    BITCODE_2DPOINT ins_pt = {.x = x, .y = y};
    text_entity->ins_pt = ins_pt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setAlignmentPtNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    BITCODE_2DPOINT alignment_pt = {.x = x, .y = y};
    text_entity->alignment_pt = alignment_pt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHorizAlignmentNative(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->horiz_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setVertAlignmentNative(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->vert_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setElevationNative(JNIEnv *env, jobject job, jlong ref, jdouble elevation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->elevation = elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setWidthFactorNative(JNIEnv *env, jobject job, jlong ref, jdouble width_factor) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->width_factor = width_factor;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setObliqueAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble oblique_angle) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    text_entity->oblique_angle = oblique_angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setExtrusionNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    Dwg_Bitcode_3BD extrusion = {.x = x, .y = y, .z = z};
    text_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Text_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    return (intptr_t)text_entity->parent;
}
