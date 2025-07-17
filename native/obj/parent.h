#include <jni.h>
#ifndef DWG_OBJ_PARENT_H
#define DWG_OBJ_PARENT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLtypeNative(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_parent_getDwgNative(JNIEnv *, jobject, jlong);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLayerNative(JNIEnv *, jobject, jlong, jlong);

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Parent_getColorNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Parent_getLinewtNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLayerNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLtypeNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
