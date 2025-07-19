#include <jni.h>

#ifndef DWG_ENTITY_ARC_H
#define DWG_ENTITY_ARC_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setCenter(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setRadius(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setStartAngle(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setEndAngle(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Arc_getParent(JNIEnv *, jobject, jlong);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getCenter(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getRadius(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getExtrusion(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getStartAngle(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getEndAngle(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


