#include <jni.h>
#include "objectref.h"
#include <dwg_api.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRefNative(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    return (jlong)ref_entity->absolute_ref;
}

JNIEXPORT jshort JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getR11IdxNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    return (jshort)ref_entity->r11_idx;
}
