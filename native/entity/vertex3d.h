#ifndef _VERTEX3D_H_
#define _VERTEX3D_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_setPoint(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getPoint(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif

#endif 