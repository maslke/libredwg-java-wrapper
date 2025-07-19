#include <jni.h>

#ifndef DWG_ENTITY_RAY_H
#define DWG_ENTITY_RAY_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ray_setPointNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ray_setVectorNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Ray_getParentNative(JNIEnv *, jobject, jlong);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ray_getPointNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ray_getVectorNative(JNIEnv *, jobject, jlong);


#ifdef __cplusplus
}
#endif
#endif
