#include <jni.h>

#ifndef DWG_ENTITY_LINE_H
#define DWG_ENTITY_LINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStartNative(JNIEnv *env, jobject obj, jlong ref, jobject start);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEndNative(JNIEnv *env, jobject obj, jlong ref, jobject end);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParentNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
