#include <jni.h>
#include "objectref.h"
#include <dwg_api.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRef(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return 0;
    }
    return (jlong)ref_entity->absolute_ref;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getR11Idx(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return 0;
    }
    return (jint)ref_entity->r11_idx;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setAbsoluteRef(JNIEnv *env, jobject job, jlong ref, jlong absoluteRef) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return;
    }
    ref_entity->absolute_ref = absoluteRef;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setR11Idx(JNIEnv *env, jobject job, jlong ref, jint r11Idx) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return;
    }
    ref_entity->r11_idx = r11Idx;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getObject(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)(ref_entity->obj));
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setObject(JNIEnv *env, jobject job, jlong ref, jobject object) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return;
    }
    ref_entity->obj = (Dwg_Object *)(intptr_t)object;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getHandleRef(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgHandle";
    return create_object(env, class_name, (jlong)(intptr_t)(&ref_entity->handleref));
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setHandleRef(JNIEnv *env, jobject job, jlong ref, jobject handleRef) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    if (ref_entity == NULL) {
        return;
    }
    jclass handleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgHandle");
    if (handleClass == NULL) {
        return;
    }
    jfieldID handleRefField = (*env)->GetFieldID(env, handleClass, "ref", "J");
    if (handleRefField == NULL) {
        (*env)->DeleteLocalRef(env, handleClass);
        return;
    }
    jlong handleRefValue = (*env)->GetLongField(env, handleRef, handleRefField);
    (*env)->DeleteLocalRef(env, handleClass);
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)handleRefValue;
    ref_entity->handleref = *handle;
}
