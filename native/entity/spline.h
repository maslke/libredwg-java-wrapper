#include <jni.h>

#ifndef DWG_ENTITY_SPLINE_H
#define DWG_ENTITY_SPLINE_H
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFlag(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setScenario(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setDegree(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setSplineFlags(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnotParam(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFitTol(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setBegTanVec(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setEndTanVec(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setClosedb(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setPeriodic(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setRational(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setWeighted(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnotTol(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setCtrlTol(JNIEnv *, jobject, jlong, jdouble);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumFitPts(JNIEnv *, jobject, jlong, jint);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFitPts(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumKnots(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnots(JNIEnv *, jobject, jlong, jobject);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumCtrlPts(JNIEnv *, jobject, jlong, jlong);
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setControlPoints(JNIEnv *, jobject, jlong, jobject);

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getParent(JNIEnv *, jobject, jlong);

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getFlag(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getScenario(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getDegree(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getSplineFlags(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnotParam(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getFitTol(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getBegTanVec(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getEndTanVec(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getClosedb(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getPeriodic(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getRational(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getWeighted(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnotTol(JNIEnv *, jobject, jlong);
JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getCtrlTol(JNIEnv *, jobject, jlong);
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumFitPts(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getFitPts(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumKnots(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnots(JNIEnv *, jobject, jlong);
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumCtrlPts(JNIEnv *, jobject, jlong);
JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getControlPoints(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif 