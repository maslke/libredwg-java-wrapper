#include <jni.h>
#ifndef DWG_OBJ_OBJECTREF_H
#define DWG_OBJ_OBJECTREF_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getHandleRef(JNIEnv *, jobject, jlong);
JNIEXPORT jlong  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRef(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getR11Idx(JNIEnv *, jobject, jlong);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setHandleRef(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setAbsoluteRef(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setR11Idx(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getObject(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_setObject(JNIEnv *, jobject, jlong, jobject);

#ifdef __cplusplus
}
#endif
#endif
