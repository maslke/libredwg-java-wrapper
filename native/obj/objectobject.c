#include <jni.h>
#include <stdio.h>
#include "objectobject.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "dwg.h"
#include "helper.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjId(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return 0;
    }
    return object->objid;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getDwg(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    jclass dwgClass = (*env)->FindClass(env, "io/github/maslke/dwg/Dwg");
    if (dwgClass == NULL) {
        return NULL;
    }
    jmethodID dwgConstructor = (*env)->GetMethodID(env, dwgClass, "<init>", "()V");
    if (dwgConstructor == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    jobject dwg = (*env)->NewObject(env, dwgClass, dwgConstructor);
    if (dwg == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, dwgClass, "ref", "J");
    if (refField == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    (*env)->SetLongField(env, dwg, refField, (jlong)object->dwg);
    (*env)->DeleteLocalRef(env, dwgClass);
    return dwg;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getBlockHeader(JNIEnv *env, jobject job, jlong ref) { 
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_BLOCK_HEADER *block_header = object->tio.BLOCK_HEADER;
    if (block_header == NULL) {
        return NULL;
    }
    jclass blockHeaderClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectBlockHeader");
    if (blockHeaderClass == NULL) {
        return NULL;
    }
    jmethodID blockHeaderConstructor = (*env)->GetMethodID(env, blockHeaderClass, "<init>", "()V");
    if (blockHeaderConstructor == NULL) {
        (*env)->DeleteLocalRef(env, blockHeaderClass);
        return NULL;
    }
    jobject blockHeader = (*env)->NewObject(env, blockHeaderClass, blockHeaderConstructor);
    if (blockHeader == NULL) {
        (*env)->DeleteLocalRef(env, blockHeaderClass);
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, blockHeaderClass, "ref", "J");
    if (refField == NULL) {
        (*env)->DeleteLocalRef(env, blockHeaderClass);
        return NULL;
    }
    (*env)->SetLongField(env, blockHeader, refField, (jlong)block_header);
    (*env)->DeleteLocalRef(env, blockHeaderClass);
    return blockHeader;
}