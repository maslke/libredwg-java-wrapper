#include <jni.h>

#ifndef DWG_ENTITY_ENDBLK_H
#define DWG_ENTITY_ENDBLK_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_EndBlk_getParent(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
