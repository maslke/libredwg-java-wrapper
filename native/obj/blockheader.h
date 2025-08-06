#include <jni.h>
#ifndef DWG_OBJ_BLOCKHEADER_H
#define DWG_OBJ_BLOCKHEADER_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPoint(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLine(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addText(JNIEnv *, jobject, jlong, jstring, jobject, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addMText(JNIEnv *, jobject, jlong, jstring, jobject, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircle(JNIEnv *, jobject, jlong, jobject, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArc(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipse(JNIEnv *, jobject, jlong, jobject, jdouble, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addInsert(JNIEnv *, jobject, jlong, jobject, jstring, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addBlock(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEndBlk(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLwpolyline(JNIEnv *, jobject, jlong, jobject points);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addRay(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addSolid(JNIEnv *, jobject, jlong, jobject, jobject, jobject, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addShape(JNIEnv *, jobject, jlong, jstring, jobject, jdouble, jdouble);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPolyline3d(JNIEnv *, jobject, jlong, jobject points);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPolyline2d(JNIEnv *, jobject, jlong, jobject points);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addXLine(JNIEnv *, jobject, jlong, jobject, jobject);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addSpline(JNIEnv *, jobject, jlong, jobject, jobject, jobject);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getOwnObjects(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getName(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getParent(JNIEnv *, jobject, jlong);
JNIEXPORT void    JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_setName(JNIEnv *, jobject, jlong, jstring);
#ifdef __cplusplus
}
#endif
#endif
