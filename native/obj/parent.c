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
#include "cjson/cJSON.h"
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *env, jobject job, jlong ref, jint color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->color.index = color;
    entity->color.flag = 0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->linewt = dxf_find_lweight(linewt);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLtypeNative(JNIEnv *env, jobject job, jlong ref, jlong ltype) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *ltype_ref = (Dwg_Object_Ref*)(intptr_t)ltype;
    entity->ltype = ltype_ref;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLayerNative(JNIEnv *env, jobject job, jlong ref, jlong layer) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *layer_ref = (Dwg_Object_Ref*)(intptr_t)layer;
    entity->layer = layer_ref;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Parent_getDwgNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    return (jlong)(intptr_t)entity->dwg;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getColorNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    return (jint)entity->color.index;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getLinewtNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    int type = entity->linewt;
    return find_linewt_by_index(type);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLayerNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *layer = entity->layer;
    return createDwgObjectRef(env, layer);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLtypeNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *ltype = entity -> ltype;
    return createDwgObjectRef(env, ltype);
}

// end parent
