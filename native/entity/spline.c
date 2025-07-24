#include <jni.h>
#include <stdio.h>
#include "spline.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->flag = flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setScenario(JNIEnv *env, jobject obj, jlong ref, jint scenario) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->scenario = scenario;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setDegree(JNIEnv *env, jobject obj, jlong ref, jint degree) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->degree = degree;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setSplineFlags(JNIEnv *env, jobject obj, jlong ref, jlong splineFlags) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->splineflags = splineFlags;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnotParam(JNIEnv *env, jobject obj, jlong ref, jlong knotParam) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->knotparam = knotParam;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFitTol(JNIEnv *env, jobject obj, jlong ref, jdouble fitTol) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->fit_tol = fitTol;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setBegTanVec(JNIEnv *env, jobject obj, jlong ref, jobject begTanVec) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || begTanVec == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, begTanVec);
    if (cls == NULL) {
        return;
    }
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    spline_entity->beg_tan_vec.x = (*env)->CallDoubleMethod(env, begTanVec, getX);
    spline_entity->beg_tan_vec.y = (*env)->CallDoubleMethod(env, begTanVec, getY);
    spline_entity->beg_tan_vec.z = (*env)->CallDoubleMethod(env, begTanVec, getZ);
    (*env)->DeleteLocalRef(env, cls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setEndTanVec(JNIEnv *env, jobject obj, jlong ref, jobject endTanVec) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || endTanVec == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, endTanVec);
    if (cls == NULL) {
        return;
    }
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    spline_entity->end_tan_vec.x = (*env)->CallDoubleMethod(env, endTanVec, getX);
    spline_entity->end_tan_vec.y = (*env)->CallDoubleMethod(env, endTanVec, getY);
    spline_entity->end_tan_vec.z = (*env)->CallDoubleMethod(env, endTanVec, getZ);
    (*env)->DeleteLocalRef(env, cls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setClosedb(JNIEnv *env, jobject obj, jlong ref, jint closedb) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->closed_b = closedb;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setPeriodic(JNIEnv *env, jobject obj, jlong ref, jint periodic) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->periodic = periodic;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setRational(JNIEnv *env, jobject obj, jlong ref, jint rational) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->rational = rational;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setWeighted(JNIEnv *env, jobject obj, jlong ref, jint weighted) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->weighted = weighted;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnotTol(JNIEnv *env, jobject obj, jlong ref, jdouble knotTol) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->knot_tol = knotTol;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setCtrlTol(JNIEnv *env, jobject obj, jlong ref, jdouble ctrlTol) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->ctrl_tol = ctrlTol;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumFitPts(JNIEnv *env, jobject obj, jlong ref, jint numFitPts) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->num_fit_pts = numFitPts;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setFitPts(JNIEnv *env, jobject obj, jlong ref, jobject fitPts) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || fitPts == NULL) {
        return;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return;
    }
    jmethodID get = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID size = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint length = (*env)->CallIntMethod(env, fitPts, size);

    if (spline_entity->fit_pts != NULL) {
        free(spline_entity->fit_pts);
    }
    
    spline_entity->fit_pts = malloc(length * sizeof(dwg_point_3d));
    spline_entity->num_fit_pts = length;
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return;
    }
    for (jint i = 0; i < length; i++) {
        jobject point = (*env)->CallObjectMethod(env, fitPts, get, i);
        jmethodID getX = (*env)->GetMethodID(env, pointClass, "getX", "()D");
        jmethodID getY = (*env)->GetMethodID(env, pointClass, "getY", "()D");
        jmethodID getZ = (*env)->GetMethodID(env, pointClass, "getZ", "()D");
        
        spline_entity->fit_pts[i].x = (*env)->CallDoubleMethod(env, point, getX);
        spline_entity->fit_pts[i].y = (*env)->CallDoubleMethod(env, point, getY);
        spline_entity->fit_pts[i].z = (*env)->CallDoubleMethod(env, point, getZ);        
    }
    (*env)->DeleteLocalRef(env, pointClass);
    (*env)->DeleteLocalRef(env, listClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumKnots(JNIEnv *env, jobject obj, jlong ref, jlong numKnots) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->num_knots = numKnots;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setKnots(JNIEnv *env, jobject obj, jlong ref, jobject knots) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || knots == NULL) {
        return;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return;
    }
    jmethodID get = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID size = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint length = (*env)->CallIntMethod(env, knots, size);

    if (spline_entity->knots != NULL) {
        free(spline_entity->knots);
    }
    
    spline_entity->knots = (double*)malloc(length * sizeof(double));
    spline_entity->num_knots = length;
    
    jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
    if (doubleClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return;
    }
    jmethodID doubleValue = (*env)->GetMethodID(env, doubleClass, "doubleValue", "()D");
    for (jint i = 0; i < length; i++) {
        jobject doubleObj = (*env)->CallObjectMethod(env, knots, get, i);
        spline_entity->knots[i] = (*env)->CallDoubleMethod(env, doubleObj, doubleValue);
    }
    (*env)->DeleteLocalRef(env, doubleClass);
    (*env)->DeleteLocalRef(env, listClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setNumCtrlPts(JNIEnv *env, jobject obj, jlong ref, jlong numCtrlPts) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return;
    }
    spline_entity->num_ctrl_pts = numCtrlPts;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Spline_setControlPoints(JNIEnv *env, jobject obj, jlong ref, jobject ctrlPts) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || ctrlPts == NULL) {
        return;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return;
    }
    jmethodID get = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID size = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint length = (*env)->CallIntMethod(env, ctrlPts, size);
    
    if (spline_entity->ctrl_pts != NULL) {
        free(spline_entity->ctrl_pts);
    }
    
    spline_entity->ctrl_pts = malloc(length * sizeof(Dwg_SPLINE_control_point));
    spline_entity->num_ctrl_pts = length;

    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return;
    }
    jmethodID getX = (*env)->GetMethodID(env, pointClass, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, pointClass, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, pointClass, "getZ", "()D");
    
    for (jint i = 0; i < length; i++) {
        jobject point = (*env)->CallObjectMethod(env, ctrlPts, get, i);
        spline_entity->ctrl_pts[i].x = (*env)->CallDoubleMethod(env, point, getX);
        spline_entity->ctrl_pts[i].y = (*env)->CallDoubleMethod(env, point, getY);
        spline_entity->ctrl_pts[i].z = (*env)->CallDoubleMethod(env, point, getZ);
    }
    (*env)->DeleteLocalRef(env, pointClass);
    (*env)->DeleteLocalRef(env, listClass);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)spline_entity->parent;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getScenario(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->scenario;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getDegree(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->degree;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getSplineFlags(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->splineflags;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnotParam(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->knotparam;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getFitTol(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0.0;
    }
    return spline_entity->fit_tol;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getBegTanVec(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID init = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    jobject vector = (*env)->NewObject(env, vectorClass, init, 
                                       spline_entity->beg_tan_vec.x, 
                                       spline_entity->beg_tan_vec.y, 
                                       spline_entity->beg_tan_vec.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getEndTanVec(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID init = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    jobject vector = (*env)->NewObject(env, vectorClass, init, 
                                       spline_entity->end_tan_vec.x, 
                                       spline_entity->end_tan_vec.y, 
                                       spline_entity->end_tan_vec.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getClosedb(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->closed_b;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getPeriodic(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->periodic;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getRational(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->rational;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getWeighted(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->weighted;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnotTol(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0.0;
    }
    return spline_entity->knot_tol;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Spline_getCtrlTol(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0.0;
    }
    return spline_entity->ctrl_tol;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumFitPts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->num_fit_pts;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getFitPts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || spline_entity->fit_pts == NULL) {
        return NULL;
    }
    
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }
    jmethodID listInit = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listClass, listInit);
    jmethodID add = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jmethodID pointInit = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    
    for (int i = 0; i < spline_entity->num_fit_pts; i++) {
        jobject point = (*env)->NewObject(env, pointClass, pointInit, 
                                          spline_entity->fit_pts[i].x,
                                          spline_entity->fit_pts[i].y,
                                          spline_entity->fit_pts[i].z);
        (*env)->CallBooleanMethod(env, list, add, point);
    }
    
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, pointClass);
    return list;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumKnots(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->num_knots;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getKnots(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || spline_entity->knots == NULL) {
        return NULL;
    }
    
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }
    jmethodID listInit = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listClass, listInit);
    jmethodID add = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    
    jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
    if (doubleClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jmethodID doubleInit = (*env)->GetMethodID(env, doubleClass, "<init>", "(D)V");
    
    for (int i = 0; i < spline_entity->num_knots; i++) {
        jobject doubleObj = (*env)->NewObject(env, doubleClass, doubleInit, spline_entity->knots[i]);
        (*env)->CallBooleanMethod(env, list, add, doubleObj);
    }
    
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, doubleClass);
    return list;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Spline_getNumCtrlPts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL) {
        return 0;
    }
    return spline_entity->num_ctrl_pts;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Spline_getControlPoints(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_SPLINE *spline_entity = (Dwg_Entity_SPLINE*)(intptr_t)ref;
    if (spline_entity == NULL || spline_entity->ctrl_pts == NULL) {
        return NULL;
    }
    
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }
    jmethodID listInit = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listClass, listInit);
    jmethodID add = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jmethodID pointInit = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    
    for (int i = 0; i < spline_entity->num_ctrl_pts; i++) {
        jobject point = (*env)->NewObject(env, pointClass, pointInit, 
                                          spline_entity->ctrl_pts[i].x,
                                          spline_entity->ctrl_pts[i].y,
                                          spline_entity->ctrl_pts[i].z);
        (*env)->CallBooleanMethod(env, list, add, point);
    }
    
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, pointClass);
    return list;
} 