#include <jni.h>
#ifndef _Included_io_github_maslke_dwg_Dwg
#define _Included_io_github_maslke_dwg_Dwg
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersion
  (JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setXNative(JNIEnv *env, jobject obj, jlong ref, jdouble x);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setYNative(JNIEnv *env, jobject obj, jlong ref, jdouble y);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZNative(JNIEnv *env, jobject obj, jlong ref, jdouble z);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_SetStart(JNIEnv *env, jobject obj, jlong ref, jobject start);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_SetEnd(JNIEnv *env, jobject obj, jlong ref, jobject end);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addPointNative(JNIEnv *env, jobject obj, jlong ref,
jdouble x, jdouble y, jdouble z);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addLineNative(JNIEnv *env, jobject obj, jlong ref,
jobject start, jobject end
);


#ifdef __cplusplus
}
#endif
#endif
