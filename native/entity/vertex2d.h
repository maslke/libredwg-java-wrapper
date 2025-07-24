#ifndef _VERTEX2D_H_
#define _VERTEX2D_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setPoint(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getPoint(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setStartWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getStartWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setEndWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getEndWidth(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setId(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getId(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setBulge(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getBulge(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setTangentDir(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getTangentDir(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif

#endif
