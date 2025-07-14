#include <jni.h>
#include <stdio.h>
#include "block.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_Dwg_entity_Block_setNameNative(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    block_entity->name = gbk_text;
    (*env)->ReleaseStringUTFChars(env, name, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_Dwg_entity_Block_setBasePtNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    block_entity->base_pt.x = x;
    block_entity->base_pt.y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_Dwg_entity_Block_setXrefPnameNative(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    block_entity->xref_pname = gbk_text;
    (*env)->ReleaseStringUTFChars(env, name, chars);
}
