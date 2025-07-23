#include <jni.h>
#include <stdio.h>
#include "circle.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setCenter(JNIEnv *env, jobject job, jlong ref, jobject center) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    if (center == NULL) {
        return;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    circle_entity->center.x = (*env)->GetDoubleField(env, center, xField);
    circle_entity->center.y = (*env)->GetDoubleField(env, center, yField);
    circle_entity->center.z = (*env)->GetDoubleField(env, center, zField);
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setRadius(JNIEnv *env, jobject job, jlong ref, jdouble radius) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return; 
    }
    circle_entity->radius = radius;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setThickness(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    circle_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Circle_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return;
    }
    if (extrusion == NULL) {
        return;
    }
    jclass vectorCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorCls == NULL) {
        return;
    }

    jfieldID xField = (*env)->GetFieldID(env, vectorCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorCls, "z", "D");
    circle_entity->extrusion.x = (*env)->GetDoubleField(env, extrusion, xField);
    circle_entity->extrusion.y = (*env)->GetDoubleField(env, extrusion, yField);
    circle_entity->extrusion.z = (*env)->GetDoubleField(env, extrusion, zField);
    (*env)->DeleteLocalRef(env, vectorCls);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Circle_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return (intptr_t)circle_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Circle_getCenter(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, circle_entity->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, circle_entity->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, circle_entity->center.z);
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Circle_getRadius(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return circle_entity->radius;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Circle_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
        return 0;
    }
    return circle_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Circle_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_CIRCLE *circle_entity = (Dwg_Entity_CIRCLE*)(intptr_t)ref;
    if (circle_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, circle_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, circle_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, circle_entity->extrusion.z);
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}
