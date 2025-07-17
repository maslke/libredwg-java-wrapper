#include <jni.h>
#ifndef DWG_OBJ_BLOCKHEADER_H
#define DWG_OBJ_BLOCKHEADER_H
#ifdef __cplusplus
extern "C" {
#endif

// block header
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPointNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLineNative(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addTextNative(JNIEnv *, jobject, jlong, jstring, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircleNative(JNIEnv *, jobject, jlong, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArcNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipseNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addInsertNative(JNIEnv *, jobject, jlong, jobject, jstring, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addBlockNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEndBlkNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLwpolylineNative(JNIEnv *, jobject, jlong, jint, jobject points);
// end block header


#ifdef __cplusplus
}
#endif
#endif
