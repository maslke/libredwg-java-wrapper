#include <jni.h>

#ifndef DWG_ENTITY_TEXT_H
#define DWG_ENTITY_TEXT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setTextValueNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHeightNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setRotationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setInsPtNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setAlignmentPtNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHorizAlignmentNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setVertAlignmentNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setElevationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setWidthFactorNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setObliqueAngleNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT long JNICALL Java_io_github_maslke_dwg_entity_Text_getParentNative(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setStyleNative(JNIEnv *, jobject, jlong, jlong);


JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Text_getTextValueNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getRotationNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getElevationNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getThicknessNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getExtrusionNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getHeightNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getWidthFactorNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getHorizAlignmentNative(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getVertAlignmentNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getInsPtNative(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getObliqueAngleNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getAlignmentPtNative(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getStyleNative(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


