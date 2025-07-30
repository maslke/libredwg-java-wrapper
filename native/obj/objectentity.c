#include <jni.h>
#include <stdio.h>
#include "objectentity.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setColor(JNIEnv *env, jobject job, jlong ref, jobject color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass colorClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgColor");
    if (colorClass == NULL) {
        return;
    }
    jmethodID refMethod = (*env)->GetMethodID(env, colorClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, color, refMethod);
    if (reference > 0) {
        Dwg_Color *ref_color = (Dwg_Color *)(intptr_t)reference;
        entity->color = *ref_color;
    }
    else {
        jmethodID indexMethod = (*env)->GetMethodID(env, colorClass, "getIndex", "()I");
        jint index = (*env)->CallIntMethod(env, color, indexMethod);
        entity->color.index = index;
    }
    (*env)->DeleteLocalRef(env, colorClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLinewt(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    entity->linewt = dxf_find_lweight(linewt);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLtype(JNIEnv *env, jobject job, jlong ref, jobject ltype) {
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
        (*env)->DeleteLocalRef(env, styleClass);
        return;
    }
    jlong ltype_ref = (*env)->CallLongMethod(env, ltype, styleMethod);
    entity->ltype = (Dwg_Object_Ref*)(intptr_t)ltype_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLayer(JNIEnv *env, jobject job, jlong ref, jobject layer) {
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
        (*env)->DeleteLocalRef(env, styleClass);
        return;
    }
    jlong layer_ref = (*env)->CallLongMethod(env, layer, styleMethod);
    entity->layer = (Dwg_Object_Ref*)(intptr_t)layer_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getDwg(JNIEnv *env, jobject job, jlong ref) {
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
    (*env)->SetLongField(env, dwg, refField, (jlong)entity->dwg);
    (*env)->DeleteLocalRef(env, dwgClass);
    return dwg;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getColor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    return createDwgColor(env, &entity->color);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLinewt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    int type = entity->linewt;
    return find_linewt_by_index(type);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLayer(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *layer = entity->layer;
    return createDwgObjectRef(env, layer);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLtype(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *ltype = entity -> ltype;
    return createDwgObjectRef(env, ltype);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntity(JNIEnv *env, jobject job, jlong ref, jint entityType) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    return NULL;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getObjId(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    return entity->objid;
}
