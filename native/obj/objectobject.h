#include <jni.h>
#ifndef DWG_OBJ_OBJECT_OBJECT_H
#define DWG_OBJ_OBJECT_OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getObjId(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getDwg(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectObject_getBlockHeader(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
