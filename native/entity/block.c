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
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setName(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return;
    }
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    block_entity->name = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, name, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setBasePt(JNIEnv *env, jobject obj, jlong ref, jobject pt) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    if (pointClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    block_entity->base_pt.x = (*env)->GetDoubleField(env, pt, xField);
    block_entity->base_pt.y = (*env)->GetDoubleField(env, pt, yField);
    (*env)->DeleteLocalRef(env, pointClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setXrefPname(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return;
    }
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    block_entity->xref_pname = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, name, chars);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Block_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)block_entity->parent;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Block_getName(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return NULL;
    }
    char *chars = block_entity->name;
    if (chars == NULL) {
        return NULL;
    }
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jstring JNICALL Java_io_github_maske_dwg_entity_Block_getXrefPname(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return NULL;
    }
    char *chars = block_entity->xref_pname;
    if (chars == NULL) {
        return NULL;
    }
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Block_getBasePt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_BLOCK *block_entity = (Dwg_Entity_BLOCK*)(intptr_t)ref;
    if (block_entity == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointClass, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointClass, constructor);
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    (*env)->SetDoubleField(env, pointObj, xField, block_entity->base_pt.x);
    (*env)->SetDoubleField(env, pointObj, yField, block_entity->base_pt.y);
    (*env)->DeleteLocalRef(env, pointClass);
    return pointObj;

}
