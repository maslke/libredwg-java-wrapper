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
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumVertexidsNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setVertexidsNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setWidthsNative(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getParentNative(JNIEnv *, jobject, jlong);

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getFlagNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getConstWidthNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getThicknessNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getElevationNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getExtrusionNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumPointsNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getPointsNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumBulgesNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getBuldgesNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumVertexidsNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getVertexidsNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getWidthsNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
