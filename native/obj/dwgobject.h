#include <jni.h>
#ifndef DWG_OBJ_DWG_OBJECT_H
#define DWG_OBJ_DWG_OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getTioEntity(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getTioObject(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getHandle(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getParent(JNIEnv *, jobject, jlong);


#ifdef __cplusplus
}
#endif
#endif
