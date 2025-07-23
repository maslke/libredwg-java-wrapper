#include <jni.h>

#ifndef DWG_ENTITY_IMAGE_H
#define DWG_ENTITY_IMAGE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClassVersion(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setPt0(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setUVec(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setVVec(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setSize(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setDisplayProps(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipping(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setBrightness(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setContrast(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setFade(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipMode(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipBoundaryType(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setNumClipVerts(JNIEnv *, jobject, jlong, jlong);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipVerts(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setImageDef(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setImageDefReactor(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getClassVersion(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getPt0(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getUVec(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getVVec(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getSize(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getDisplayProps(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipping(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getBrightness(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getContrast(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getFade(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipMode(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipBoundaryType(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getNumClipVerts(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getClipVerts(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getImageDef(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getImageDefReactor(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif


