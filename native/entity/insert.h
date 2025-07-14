#include <jni.h>

#ifndef DWG_ENTITY_INSERT_H
#define DWG_ENTITY_INSERT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setInsPtNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleFlagNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRotationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setHasAttribsNative(JNIEnv *, jobject, jlong, jint);


#ifdef __cplusplus
}
#endif
#endif
