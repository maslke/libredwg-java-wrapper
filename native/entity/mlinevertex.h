#include <jni.h>

#ifndef DWG_ENTITY_MLINEVERTEX_H
#define DWG_ENTITY_MLINEVERTEX_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setVertex(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getVertex(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setVertexDirection(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getVertexDirection(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setMiterDirection(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getMiterDirection(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setNumLines(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getNumLines(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setLines(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getLines(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getParent(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
