#include <jni.h>
#include "vport.h"
#include <dwg_api.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewCtrNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->VIEWCTR.x = x;
    vport->VIEWCTR.y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewSizeNative(JNIEnv *env, jobject job, jlong ref, jdouble viewSize) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->VIEWSIZE = viewSize;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewWidthNative(JNIEnv *env, jobject job, jlong ref, jdouble viewWidth) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->view_width = viewWidth;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setAspectRatioNative(JNIEnv *env, jobject job, jlong ref, jdouble aspectRatio) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->aspect_ratio = aspectRatio;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewTargetNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->view_target.x = x;
    vport->view_target.y = y;
    vport->view_target.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setContrastNative(JNIEnv *env, jobject job, jlong ref, jdouble contrast) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->contrast = contrast;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setBrightnessNative(JNIEnv *env, jobject job, jlong ref, jdouble brightness) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->brightness = brightness;
}
