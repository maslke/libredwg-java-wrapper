#include <jni.h>

#ifndef DWG_ENTITY_BLOCK_H
#define DWG_ENTITY_BLOCK_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setNameNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setBasePtNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Block_setXrefPnameNative(JNIEnv *, jobject, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
