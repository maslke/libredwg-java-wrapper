#include <jni.h>
#include <stdio.h>
#include "ellipse.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setCenter(JNIEnv *env, jobject job, jlong ref, jobject point) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    if (point == NULL) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, xField);
    jdouble y = (*env)->GetDoubleField(env, point, yField);
    jdouble z = (*env)->GetDoubleField(env, point, zField);
    BITCODE_3BD center = {.x = x, .y = y, .z = z};
    ellipse->center = center;
    (*env)->DeleteLocalRef(env, pointClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setMajorAxis(JNIEnv *env, jobject job, jlong ref, jdouble major_axis) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    BITCODE_3BD sm_axis = {.x = major_axis, .y = major_axis, .z = 0};
    sm_axis.z = ellipse->center.z;
    ellipse->sm_axis = sm_axis;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setAxisRatio(JNIEnv *env, jobject job, jlong ref, jdouble ratio) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    ellipse->axis_ratio = ratio;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    if (extrusion == NULL) {
        return;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, extrusion, xField);
    jdouble y = (*env)->GetDoubleField(env, extrusion, yField);
    jdouble z = (*env)->GetDoubleField(env, extrusion, zField);
    BITCODE_3BD extrusion2 = {.x = x, .y = y, .z = z};
    ellipse->extrusion = extrusion2;
    (*env)->DeleteLocalRef(env, vectorClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setStartAngle(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    ellipse->start_angle = angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ellipse_setEndAngle(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return;
    }
    ellipse->end_angle = angle;
}


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)ellipse->parent;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getStartAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return 0;
    }
    return ellipse->start_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getEndAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return 0;
    }
    return ellipse->end_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getMajorAxis(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return 0;
    }
    return ellipse->sm_axis.x;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getAxisRatio(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return 0;
    }
    return ellipse->axis_ratio;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getCenter(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, ellipse->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, ellipse->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, ellipse->center.z);
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ellipse_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ELLIPSE *ellipse = (Dwg_Entity_ELLIPSE*)(intptr_t)ref;
    if (ellipse == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, vectorClass, "<init>", "()V");
    jobject vectorObj = (*env)->NewObject(env, vectorClass, constructor);

    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    (*env)->SetDoubleField(env, vectorObj, xField, ellipse->extrusion.x);
    (*env)->SetDoubleField(env, vectorObj, yField, ellipse->extrusion.y);
    (*env)->SetDoubleField(env, vectorObj, zField, ellipse->extrusion.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vectorObj;
}

