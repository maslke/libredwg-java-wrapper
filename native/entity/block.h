#include <jni.h>

#ifndef DWG_ENTITY_BLOCK_H
#define DWG_ENTITY_BLOCK_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setName(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setBasePt(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setXrefPname(JNIEnv *, jobject, jlong, jstring);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Block_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Block_getName(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Block_getBasePt(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Block_getXrefPname(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
