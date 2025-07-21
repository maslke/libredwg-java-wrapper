#include <jni.h>
#ifndef DWG_OBJ_COLOR_H
#define DWG_OBJ_COLOR_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setIndex(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setRaw(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setRgb(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setMethod(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setName(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setBookName(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setHandle(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlphaRaw(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlphaType(JNIEnv *, jobject, jlong, jshort);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlpha(JNIEnv *, jobject, jlong, jint);

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getIndex(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getRaw(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getRgb(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getMethod(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getName(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getBookName(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getHandle(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlphaRaw(JNIEnv *, jobject, jlong);
JNIEXPORT jshort JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlphaType(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlpha(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
