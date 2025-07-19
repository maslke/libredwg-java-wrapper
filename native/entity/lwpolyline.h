#include <jni.h>

#ifndef DWG_ENTITY_LWPOLYLINE_H
#define DWG_ENTITY_LWPOLYLINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setConstWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setElevation(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumPoints(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setPoints(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumBulges(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setBulges(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumVertexids(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setVertexids(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setWidths(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getConstWidth(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getElevation(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getExtrusion(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumPoints(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getPoints(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumBulges(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getBulges(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumVertexids(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getVertexids(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getWidths(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
