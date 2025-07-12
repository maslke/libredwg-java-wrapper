#include <jni.h>
#ifndef _Included_io_github_maslke_dwg_Dwg
#define _Included_io_github_maslke_dwg_Dwg
#ifdef __cplusplus
extern "C" {
#endif

// dwg
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersionNative(JNIEnv *, jobject);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_createNative(JNIEnv *, jclass);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_openNative(JNIEnv *, jclass, jstring);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_Dwg_saveNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void    JNICALL Java_io_github_maslke_dwg_Dwg_setCodePageNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getObjectBlockHeaderNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_createObjectBlockHeaderNative(JNIEnv *, jobject, jlong, jstring);
// end dwg

// parent entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *, jobject, jlong, jstring);
// end


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPointNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLineNative(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addTextNative(JNIEnv *, jobject, jlong, jstring, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircleNative(JNIEnv *, jobject, jlong, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArcNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipseNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble);

#ifdef __cplusplus
}
#endif
#endif
