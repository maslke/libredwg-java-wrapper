 #ifndef _POLYLINE2D_H_
#define _POLYLINE2D_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setHasVertex(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getHasVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumOwned(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumOwned(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setFirstVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getFirstVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setLastVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getLastVertex(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setSeqend(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getSeqend(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setCurveType(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getCurveType(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setStartWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getStartWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setEndWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getEndWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setElevation(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getElevation(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtrusion(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtraR11Size(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtraR11Size(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtraR11Text(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtraR11Text(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumMVerts(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumMVerts(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumNVerts(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumNVerts(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif

#endif /* _POLYLINE2D_H_ */