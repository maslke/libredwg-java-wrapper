#include <jni.h>

#ifndef DWG_ENTITY_LINE_H
#define DWG_ENTITY_LINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStartNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEndNative(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParentNative(JNIEnv *, jobject, jlong);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getStartNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getEndNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Line_getThicknessNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getExtrusionNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
