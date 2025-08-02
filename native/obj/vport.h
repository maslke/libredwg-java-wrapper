#include <jni.h>
#ifndef DWG_OBJ_VPORT_H
#define DWG_OBJ_VPORT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewCtr(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewCtr(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewSize(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewSize(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setAspectRatio(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getAspectRatio(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewTarget(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewTarget(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setContrast(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getContrast(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setBrightness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getBrightness(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
