#include <jni.h>
#ifndef _Included_io_github_maslke_dwg_Dwg
#define _Included_io_github_maslke_dwg_Dwg
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersionNative(JNIEnv *, jobject);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_createNative(JNIEnv *, jclass);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_openNative(JNIEnv *, jclass, jstring);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_Dwg_saveNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void    JNICALL Java_io_github_maslke_dwg_Dwg_setCodePageNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getObjectBlockHeaderNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_createObjectBlockHeaderNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getBlockHeaderNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_findTableHandleNative(JNIEnv *, jobject, jlong, jstring, jstring);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_addHandleRefNative(JNIEnv *, jobject, jlong, jint, jlong, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getVportNative(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_Dwg_releaseNative(JNIEnv *, jobject, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getNumObjects(JNIEnv *, jobject, jlong);
JNIEXPORT jlong   JNICALL Java_io_github_maslke_dwg_Dwg_getNumEntities(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_Dwg_getObject(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_Dwg_getDwgHeader(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_Dwg_getNumClasses(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_Dwg_getMspaceObject(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_Dwg_getPspaceBlock(JNIEnv *, jobject, jlong);
#ifdef __cplusplus
}
#endif
#endif
