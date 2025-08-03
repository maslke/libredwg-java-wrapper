#include <jni.h>
#ifndef DWG_OBJ_OBJECT_LAYER_H
#define DWG_OBJ_OBJECT_LAYER_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getName(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setName(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setUsed(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getUsed(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefRef(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefRef(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefResolved(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefResolved(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefDep(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefDep(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setXref(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getXref(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFlag0(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFlag0(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFrozen(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFrozen(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setOn(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getOn(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFrozenInNew(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFrozenInNew(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLocked(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLocked(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getPlotFlag(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setPlotFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLinewt(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLinewt(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getColor(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setColor(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getPlotStyle(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setPlotStyle(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getMaterial(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setMaterial(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLtype(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLtype(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getVisualStyle(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setVisualStyle(JNIEnv *, jobject, jlong, jobject);

#ifdef __cplusplus
}
#endif
#endif
