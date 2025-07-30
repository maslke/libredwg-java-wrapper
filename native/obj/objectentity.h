#include <jni.h>
#ifndef DWG_OBJ_OBJECT_ENTITY_H
#define DWG_OBJ_OBJECT_ENTITY_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setColor(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLinewt(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLtype(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void  JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLayer(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getObjId(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntity(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getDwg(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getColor(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLinewt(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLayer(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLtype(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntMode(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
