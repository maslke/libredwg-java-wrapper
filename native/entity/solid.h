#include <jni.h>

#ifndef DWG_ENTITY_SOLID_H
#define DWG_ENTITY_SOLID_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setElevation(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner1(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner2(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner3(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner4(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setExtrusion(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Solid_getParent(JNIEnv *, jobject, jlong);

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Solid_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Solid_getElevation(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getCorner1(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getCorner2(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getCorner3(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getCorner4(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getExtrusion(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


