#include <jni.h>

#ifndef DWG_ENTITY_ELLIPSE_H
#define DWG_ENTITY_ELLIPSE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setCenterNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setMajorAxisNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maskle_dwg_entity_Ellipse_setAxisRatioNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setStartAngleNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setEndAngleNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getParentNative(JNIEnv *, jobject, jlong);

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getStartAngleNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getEndAngleNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getMajorAxisNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getAxisRatioNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getCenterNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getExtrusionNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


