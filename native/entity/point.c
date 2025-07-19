#include <jni.h>
#include <stdio.h>
#include "point.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setX(JNIEnv *env, jobject obj, jlong ref, jdouble x) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return;
    }
    point_entity->x = x;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setY(JNIEnv *env, jobject obj, jlong ref, jdouble y) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return;
    }
    point_entity -> y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setZ(JNIEnv *env, jobject obj, jlong ref, jdouble z) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return;
    }
    point_entity->z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return;
    }
    point_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Point_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return;
    }
    if (extrusion == NULL) {
        return;
    }
    jclass vectorCls = (*env)->GetObjectClass(env, extrusion);
    jfieldID xField = (*env)->GetFieldID(env, vectorCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorCls, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, extrusion, xField);
    jdouble y = (*env)->GetDoubleField(env, extrusion, yField);
    jdouble z = (*env)->GetDoubleField(env, extrusion, zField);
    BITCODE_BE extrusion2 = {.x = x, .y = y, .z = z};
    point_entity->extrusion = extrusion2;
    (*env)->DeleteLocalRef(env, vectorCls);
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getX(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return 0;
    }
    return point_entity->x;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getY(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return 0;
    }
    return point_entity->y;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getZ(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return 0;
    }
    return point_entity->z;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Point_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return 0;
    }
    return point_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Point_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, point_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, point_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, point_entity->extrusion.z);
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Point_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_POINT *point_entity = (Dwg_Entity_POINT*)(intptr_t)ref;
    if (point_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)point_entity->parent;
}
