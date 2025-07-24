#include <jni.h>
#include <stdio.h>
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"
#include "vertex3d.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_3D *vertex3d = (Dwg_Entity_VERTEX_3D *)(intptr_t)ref;
    if (vertex3d == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)vertex3d->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_VERTEX_3D *vertex3d = (Dwg_Entity_VERTEX_3D *)(intptr_t)ref;
    if (vertex3d == NULL) {
        return;
    }
    vertex3d->flag = (BITCODE_RC)flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_3D *vertex3d = (Dwg_Entity_VERTEX_3D *)(intptr_t)ref;
    if (vertex3d == NULL) {
        return 0;
    }
    return vertex3d->flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_setPoint(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_VERTEX_3D *vertex3d = (Dwg_Entity_VERTEX_3D *)(intptr_t)ref;
    if (vertex3d == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    vertex3d->point.x = (*env)->GetDoubleField(env, point, xField);
    vertex3d->point.y = (*env)->GetDoubleField(env, point, yField);
    vertex3d->point.z = (*env)->GetDoubleField(env, point, zField);
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Vertex3d_getPoint(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_3D *vertex3d = (Dwg_Entity_VERTEX_3D *)(intptr_t)ref;
    if (vertex3d == NULL) {
        return NULL;
    }
    jclass point_class = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (point_class == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, point_class, "<init>", "(DDD)V");
    jfieldID fidX = (*env)->GetFieldID(env, point_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, point_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, point_class, "z", "D");
    jobject point = (*env)->NewObject(env, point_class, constructor, vertex3d->point.x, vertex3d->point.y, vertex3d->point.z);
    (*env)->DeleteLocalRef(env, point_class);
    return point;
} 