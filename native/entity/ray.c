#include <jni.h>
#include <stdio.h>
#include "ray.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ray_setPoint(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_RAY *ray_entity = (Dwg_Entity_RAY*)(intptr_t)ref;
    if (ray_entity == NULL) {
        return;
    }
    jclass point_class = (*env)->GetObjectClass(env, point);
    jfieldID fidX = (*env)->GetFieldID(env, point_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, point_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, point_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    BITCODE_3BD p = {.x = x, .y = y, .z = z};
    ray_entity->point = p;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Ray_setVector(JNIEnv *env, jobject obj, jlong ref, jobject vector) {
    Dwg_Entity_RAY *ray_entity = (Dwg_Entity_RAY*)(intptr_t)ref;
    if (ray_entity == NULL) {
        return;
    }
    jclass vector_class = (*env)->GetObjectClass(env, vector);
    jfieldID fidX = (*env)->GetFieldID(env, vector_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, vector_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, vector_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, vector, fidX);
    jdouble y = (*env)->GetDoubleField(env, vector, fidY);
    jdouble z = (*env)->GetDoubleField(env, vector, fidZ);
    BITCODE_3BD v = {.x = x, .y = y, .z = z};
    ray_entity->vector = v;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Ray_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_RAY *ray_entity = (Dwg_Entity_RAY*)(intptr_t)ref;
    if (ray_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)ray_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ray_getPoint(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_RAY *ray_entity = (Dwg_Entity_RAY*)(intptr_t)ref;
    if (ray_entity == NULL) {
        return NULL;
    }
    jclass point_class = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    jmethodID constructor = (*env)->GetMethodID(env, point_class, "<init>", "(DDD)V");
    jfieldID fidX = (*env)->GetFieldID(env, point_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, point_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, point_class, "z", "D");
    jdouble x = ray_entity->point.x;
    jdouble y = ray_entity->point.y;
    jdouble z = ray_entity->point.z;
    jobject point = (*env)->NewObject(env, point_class, constructor, x, y, z);
    return point;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Ray_getVector(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_RAY *ray_entity = (Dwg_Entity_RAY*)(intptr_t)ref;
    if (ray_entity == NULL) {
        return NULL;
    }
    jclass vector_class = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    jmethodID constructor = (*env)->GetMethodID(env, vector_class, "<init>", "(DDD)V");
    jfieldID fidX = (*env)->GetFieldID(env, vector_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, vector_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, vector_class, "z", "D");
    jdouble x = ray_entity->vector.x;
    jdouble y = ray_entity->vector.y;
    jdouble z = ray_entity->vector.z;
    jobject vector = (*env)->NewObject(env, vector_class, constructor, x, y, z);
    return vector;
}