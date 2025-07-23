#include <jni.h>

#ifndef DWG_ENTITY_INSERT_H
#define DWG_ENTITY_INSERT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setInsPt(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScale(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRotation(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setHasAttribs(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumOwned(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setBlockHeader(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setFirstAttrib(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setLastAttrib(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setSeqend(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setAttribs(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumCols(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumRows(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setColSpacing(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRowSpacing(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setBlockName(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Insert_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getInsPt(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getScale(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getScaleFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getRotation(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getExtrusion(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getHasAttribs(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumOwned(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getBlockHeader(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getFirstAttrib(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getLastAttrib(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getSeqend(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getAttribs(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumCols(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumRows(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getColSpacing(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getRowSpacing(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Insert_getBlockName(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
