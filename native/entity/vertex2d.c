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
#include "vertex2d.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)vertex2d->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->flag = (BITCODE_RC)flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return vertex2d->flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setPoint(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)ref;
    if (vertex2d == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    vertex2d->point.x = (*env)->GetDoubleField(env, point, xField);
    vertex2d->point.y = (*env)->GetDoubleField(env, point, yField);
    vertex2d->point.z = (*env)->GetDoubleField(env, point, zField);
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getPoint(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
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
    jobject point = (*env)->NewObject(env, point_class, constructor, vertex2d->point.x, vertex2d->point.y, vertex2d->point.z);
    (*env)->DeleteLocalRef(env, point_class);
    return point;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setStartWidth(JNIEnv *env, jobject obj, jlong ref, jdouble startWidth) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->start_width = startWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getStartWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return vertex2d->start_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setEndWidth(JNIEnv *env, jobject obj, jlong ref, jdouble endWidth) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->end_width = endWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getEndWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return vertex2d->end_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setId(JNIEnv *env, jobject obj, jlong ref, jlong id) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->id = (BITCODE_BL)id;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getId(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return (jlong)vertex2d->id;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setBulge(JNIEnv *env, jobject obj, jlong ref, jdouble bulge) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->bulge = bulge;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getBulge(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return vertex2d->bulge;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_setTangentDir(JNIEnv *env, jobject obj, jlong ref, jdouble tangentDir) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return;
    }
    vertex2d->tangent_dir = tangentDir;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Vertex2d_getTangentDir(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_VERTEX_2D *vertex2d = (Dwg_Entity_VERTEX_2D *)(intptr_t)ref;
    if (vertex2d == NULL) {
        return 0;
    }
    return vertex2d->tangent_dir;
}
