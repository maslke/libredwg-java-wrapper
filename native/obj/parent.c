#include <jni.h>
#include <stdio.h>
#include "parent.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColor(JNIEnv *env, jobject job, jlong ref, jint color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    entity->color.index = color;
    entity->color.flag = 0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewt(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    entity->linewt = dxf_find_lweight(linewt);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLtype(JNIEnv *env, jobject job, jlong ref, jobject ltype) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (styleClass == NULL) {
        return;
    }
    jmethodID styleMethod = (*env)->GetMethodID(env, styleClass, "getRef", "()J");
    if (styleMethod == NULL) {
        return;
    }
    jlong ltype_ref = (*env)->CallLongMethod(env, ltype, styleMethod);
    entity->ltype = (Dwg_Object_Ref*)(intptr_t)ltype_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLayer(JNIEnv *env, jobject job, jlong ref, jobject layer) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (styleClass == NULL) {
        return;
    }
    jmethodID styleMethod = (*env)->GetMethodID(env, styleClass, "getRef", "()J");
    if (styleMethod == NULL) {
        return;
    }
    jlong layer_ref = (*env)->CallLongMethod(env, layer, styleMethod);
    entity->layer = (Dwg_Object_Ref*)(intptr_t)layer_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getDwg(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    jclass dwgClass = (*env)->FindClass(env, "io/github/maslke/dwg/Dwg");
    if (dwgClass == NULL) {
        return NULL;
    }
    jmethodID dwgConstructor = (*env)->GetMethodID(env, dwgClass, "<init>", "()V");
    if (dwgConstructor == NULL) {
        return NULL;
    }
    jobject dwg = (*env)->NewObject(env, dwgClass, dwgConstructor);
    if (dwg == NULL) {
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, dwgClass, "ref", "J");
    if (refField == NULL) {
        return NULL;
    }
    (*env)->SetLongField(env, dwg, refField, (jlong)entity->dwg);
    (*env)->DeleteLocalRef(env, dwgClass);
    return dwg;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getColor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    return (jint)entity->color.index;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getLinewt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    int type = entity->linewt;
    return find_linewt_by_index(type);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLayer(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *layer = entity->layer;
    return createDwgObjectRef(env, layer);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLtype(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *ltype = entity -> ltype;
    return createDwgObjectRef(env, ltype);
}
