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
// end dwg

// parent entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *, jobject, jlong ref, jint color);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *, jobject, jlong ref, jstring ltype);
// end



JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setXNative(JNIEnv *env, jobject obj, jlong ref, jdouble x);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setYNative(JNIEnv *env, jobject obj, jlong ref, jdouble y);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZNative(JNIEnv *env, jobject obj, jlong ref, jdouble z);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z);

// line entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_SetStart(JNIEnv *env, jobject obj, jlong ref, jobject start);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_SetEnd(JNIEnv *env, jobject obj, jlong ref, jobject end);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_getParentNative(JNIEnv *, jobject, jlong);
//

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addPointNative(JNIEnv *env, jobject obj, jlong ref,
jdouble x, jdouble y, jdouble z);

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_DwgBlockHeader_addLineNative(JNIEnv *env, jobject obj, jlong ref,
jobject start, jobject end
);

// text entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setTextValueNative(JNIEnv *, jobject, jlong, jstring text);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHeightNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setRotationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setInsPtNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setAlignmentPtNative(JNIEnv *, jobject, jlong, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHorizAlignmentNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setVertAlignmentNative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setElevationNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setThicknessNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setWidthFactorNative(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setExtrusionNative(JNIEnv *, jobject, jlong, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setObliqueAngleNative(JNIEnv *, jobject, jlong, jdouble);
//



#ifdef __cplusplus
}
#endif
#endif
