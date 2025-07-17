#include <jni.h>

#ifndef DWG_ENTITY_POINT_H
#define DWG_ENTITY_POINT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setXNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setYNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Point_getParentNative(JNIEnv *, jobject, jlong);

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getXNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getYNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getZNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getThicknessNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Point_getExtrusionNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


