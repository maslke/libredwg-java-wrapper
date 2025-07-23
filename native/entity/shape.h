#include <jni.h>

#ifndef DWG_ENTITY_SHAPE_H
#define DWG_ENTITY_SHAPE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setInsPt(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setScale(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setRotation(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setWidthFactor(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setObliqueAngle(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setThickness(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setStyleId(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setStyle(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setExtrusion(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Shape_getParent(JNIEnv *, jobject, jlong);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getInsPt(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getScale(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getRotation(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getWidthFactor(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getObliqueAngle(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getThickness(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Shape_getStyleId(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getStyle(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getExtrusion(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


