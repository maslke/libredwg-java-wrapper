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

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjectBlockHeader(JNIEnv *env, jobject job, jlong ref) { 
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

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjectStyle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_STYLE *style = object->tio.STYLE;
    if (style == NULL) {
        return NULL;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectStyle");
    if (styleClass == NULL) {
        return NULL;
    }
    jmethodID styleConstructor = (*env)->GetMethodID(env, styleClass, "<init>", "()V");
    if (styleConstructor == NULL) {
        (*env)->DeleteLocalRef(env, styleClass);
        return NULL;
    }
    jobject styleobj = (*env)->NewObject(env, styleClass, styleConstructor);
    if (style == NULL) {
        (*env)->DeleteLocalRef(env, styleClass);
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, styleClass, "ref", "J");
    if (refField == NULL) {
        (*env)->DeleteLocalRef(env, styleClass);
    }
    (*env)->SetLongField(env, styleobj, refField, (jlong)style);
    (*env)->DeleteLocalRef(env, styleClass);
    return styleobj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjectVport(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_VPORT *vport = object->tio.VPORT;
    if (vport == NULL) {
        return NULL;
    }
    const char *class_names = "io/github/maslke/dwg/obj/DwgObjectVport";
    return create_object(env, class_names, (jlong)(intptr_t)vport);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjectLtype(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_LTYPE *ltype = object->tio.LTYPE;
    if (ltype == NULL) {
        return NULL;
    }
    const char *class_names = "io/github/maslke/dwg/obj/DwgObjectLtype";
    return create_object(env, class_names, (jlong)(intptr_t)ltype);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjectLayer(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Object *object = (Dwg_Object_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_LAYER *layer = object->tio.LAYER;
    if (layer == NULL) {
        return NULL;
    }
    const char *class_names = "io/github/maslke/dwg/obj/DwgObjectLayer";
    return create_object(env, class_names, (jlong)(intptr_t)layer);
}
