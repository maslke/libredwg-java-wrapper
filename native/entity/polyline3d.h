#ifndef _POLYLINE3D_H_
#define _POLYLINE3D_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setHasVertex(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getHasVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setNumVertex(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getNumVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setFirstVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getFirstVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setLastVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getLastVertex(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setSeqend(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getSeqend(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setCurveType(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getCurveType(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setStartWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getStartWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setEndWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getEndWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getExtrusion(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif

#endif
