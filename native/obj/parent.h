#include <jni.h>
#ifndef DWG_OBJ_PARENT_H
#define DWG_OBJ_PARENT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setColor(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewt(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLtype(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_entity_Parent_setLayer(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getDwg(JNIEnv *, jobject, jlong);

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Parent_getColor(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Parent_getLinewt(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLayer(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLtype(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
