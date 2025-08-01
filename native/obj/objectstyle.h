#include <jni.h>
#ifndef DWG_OBJ_OBJECT_STYLE_H
#define DWG_OBJ_OBJECT_STYLE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setIsShape(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getIsShape(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setIsVertical(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getIsVertical(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setTextSize(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getTextSize(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setWidthFactor(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getWidthFactor(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setObliqueAngle(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getObliqueAngle(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setGeneration(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getGeneration(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setLastHeight(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getLastHeight(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setFontFile(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getFontFile(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setBigFontFile(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getBigFontFile(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
