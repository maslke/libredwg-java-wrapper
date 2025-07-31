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
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getDwg(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getColor(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLinewt(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLayer(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLtype(JNIEnv *, jobject, jlong);
JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntMode(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityPoint(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityLine(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityArc(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityCircle(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityText(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityEllipse(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntitySpline(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityInsert(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityMLine(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityHatch(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityLwpolyline(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
