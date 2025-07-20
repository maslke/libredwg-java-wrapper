#include <jni.h>

#ifndef DWG_ENTITY_MTEXT_H
#define DWG_ENTITY_MTEXT_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setInsPt(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtrusion(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setXAxisDir(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setRectHeight(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setRectWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setTextHeight(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAttachment(JNIEnv *, jobject, jlong, jshort);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setFlowDir(JNIEnv *, jobject, jlong, jshort);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtentsWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtentsHeight(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setText(JNIEnv *, jobject, jlong, jstring);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setStyle(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setLinespaceStyle(JNIEnv *, jobject, jlong, jshort);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setLinespaceFactor(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setUnknownB0(JNIEnv *, jobject, jlong, jshort);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillScale(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillTrans(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setIsNotAnnotative(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setClassVersion(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setDefaultFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAppid(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setIgnoreAttachment(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnType(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setNumFragments(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnWidth(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setGutter(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAutoHeight(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setFlowReversed(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setNumColumnHeights(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnHeights(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getInsPt(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getExtrusion(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getXAxisDir(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getRectHeight(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getRectWidth(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getTextHeight(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getAttachment(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getFlowDir(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getExtentsWidth(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getExtentsHeight(JNIEnv *, jobject, jlong);
JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_MText_getText(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getStyle(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getLinespaceStyle(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getLinespaceFactor(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getUnknownB0(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillScale(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillTrans(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getIsNotAnnotative(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getClassVersion(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getDefaultFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getAppid(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getIgnoreAttachment(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnType(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getNumFragments(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnWidth(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getGutter(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getAutoHeight(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getFlowReversed(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getNumColumnHeights(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnHeights(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getParent(JNIEnv *, jobject, jlong);


#ifdef __cplusplus
}
#endif
#endif


