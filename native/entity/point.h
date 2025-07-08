#include <jni.h>

#ifndef DWG_ENTITY_POINT_H
#define DWG_ENTITY_POINT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setXNative(JNIEnv *env, jobject obj, jlong ref, jdouble x);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setYNative(JNIEnv *env, jobject obj, jlong ref, jdouble y);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZNative(JNIEnv *env, jobject obj, jlong ref, jdouble z);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z);

#ifdef __cplusplus
}
#endif
#endif


