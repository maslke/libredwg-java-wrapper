#include <jni.h>
#ifndef DWG_DWG_HANDLE_H
#define DWG_DWG_HANDLE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getCode(JNIEnv *, jobject, jlong);
JNIEXPORT jint  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getSize(JNIEnv *, jobject, jlong);
JNIEXPORT jlong  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getValue(JNIEnv *, jobject, jlong);
JNIEXPORT jint  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_getIsGlobal(JNIEnv *, jobject, jlong);

JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setCode(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setSize(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setValue(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgHandle_setIsGlobal(JNIEnv *, jobject, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
