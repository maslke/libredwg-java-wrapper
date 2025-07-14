#include <jni.h>

#ifndef DWG_ENTITY_LWPOLYLINE_H
#define DWG_ENTITY_LWPOLYLINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setFlagNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setConstWidthNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setElevationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumPointsNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setPointsNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumBulgesNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setBulgesNative(JNIEnv *, jobject, jlong, jobject);

#ifdef __cplusplus
}
#endif
#endif
