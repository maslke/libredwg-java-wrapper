#include <jni.h>

#ifndef DWG_ENTITY_LINE_H
#define DWG_ENTITY_LINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStart(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEnd(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getStart(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getEnd(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Line_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Line_getExtrusion(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
