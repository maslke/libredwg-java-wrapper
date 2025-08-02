#include <jni.h>
#include "dwghandle.h"
#include <dwg_api.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getCode(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return 0;
    }
    return (jint)handle->code;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getSize(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return 0;
    }
    return (jint)handle->size;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getIsGlobal(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return 0;
    }
    return (jint)handle->is_global;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getValue(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return 0;
    }
    return (jlong)handle->value;
}

JNIEXPORT void JNICALL  Java_io_github_maslke_dwg_obj_DwgHandle_setCode(JNIEnv *env, jobject obj, jlong ref, jint code) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return;
    }
    handle->code = code;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setSize(JNIEnv *env, jobject obj, jlong ref, jint size) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return;
    }
    handle->size = size;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setValue(JNIEnv *env, jobject obj, jlong ref, jlong value) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return;
    }
    handle->value = value;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setIsGlobal(JNIEnv *env, jobject obj, jlong ref, jint isGlobal) {
    Dwg_Handle *handle = (Dwg_Handle *)(intptr_t)ref;
    if (handle == NULL) {
        return;
    }
    handle->is_global = isGlobal;
}
