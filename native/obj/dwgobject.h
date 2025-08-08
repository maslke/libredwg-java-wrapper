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
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFixedType(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getSuperType(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedEntity(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedEntity(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedBlock(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedBlock(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getLastOwnedBlock(JNIEnv *, jobject, jlong);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedSubEntity(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedSubEntity(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextObject(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextEntity(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
