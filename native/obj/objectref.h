#include <jni.h>
#ifndef DWG_OBJ_OBJECTREF_H
#define DWG_OBJ_OBJECTREF_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRefNative(JNIEnv *, jobject, jlong);
JNIEXPORT jshort JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getR11IdxNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
