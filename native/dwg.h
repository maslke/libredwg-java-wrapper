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
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getBlockHeaderNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_findTableHandleNative(JNIEnv *, jobject, jlong, jstring, jstring);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_addHandleRefNative(JNIEnv *, jobject, jlong, jint, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getVportNative(JNIEnv *, jobject, jstring);
// end dwg

// parent entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *, jobject, jlong, jstring);
// end


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addPointNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addLineNative(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addTextNative(JNIEnv *, jobject, jlong, jstring, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addCircleNative(JNIEnv *, jobject, jlong, jobject, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addArcNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble, jdouble);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addEllipseNative(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble);


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRefNative(JNIEnv *, jobject, jlong);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewCtrNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewSizeNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewWidthNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setAspectRatioNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewTargetNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setContrastNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setBrightnessNative(JNIEnv *, jobject, jlong, jdouble);


#ifdef __cplusplus
}
#endif
#endif
