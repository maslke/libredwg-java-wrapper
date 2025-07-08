#include <jni.h>

#ifndef DWG_ENTITY_ARC_H
#define DWG_ENTITY_ARC_H
#ifdef __cplusplus
extern "C" {
#endif



JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setCenterNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setRadiusNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setStartAngleNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setEndAngleNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Arc_getParentNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


