#include <jni.h>
#include <stdio.h>
#include "arc.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setCenter(JNIEnv *env, jobject job, jlong ref, jobject center) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
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
    arc_entity->center.x = (*env)->GetDoubleField(env, center, xField);
    arc_entity->center.y = (*env)->GetDoubleField(env, center, yField);
    arc_entity->center.z = (*env)->GetDoubleField(env, center, zField);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setRadius(JNIEnv *env, jobject job, jlong ref, jdouble radius) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return;
    }
    arc_entity->radius = radius;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setThickness(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return;
    }
    arc_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
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
    arc_entity->extrusion.x = (*env)->GetDoubleField(env, extrusion, xField);
    arc_entity->extrusion.y = (*env)->GetDoubleField(env, extrusion, yField);
    arc_entity->extrusion.z = (*env)->GetDoubleField(env, extrusion, zField);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Arc_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return 0;
    }
    return (intptr_t)arc_entity->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setStartAngle(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return;
    }
    arc_entity->start_angle = angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Arc_setEndAngle(JNIEnv *env, jobject job, jlong ref, jdouble angle) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return;
    }
    arc_entity->end_angle = angle;
}


JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getCenter(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, arc_entity->center.x);
    (*env)->SetDoubleField(env, pointObj, yField, arc_entity->center.y);
    (*env)->SetDoubleField(env, pointObj, zField, arc_entity->center.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getRadius(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return 0;
    }
    return arc_entity->radius;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return 0;
    }
    return arc_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Arc_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
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
    (*env)->SetDoubleField(env, pointObj, xField, arc_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, arc_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, arc_entity->extrusion.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getStartAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return 0;
    }
    return arc_entity->start_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Arc_getEndAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_ARC *arc_entity = (Dwg_Entity_ARC*)(intptr_t)ref;
    if (arc_entity == NULL) {
        return 0;
    }
    return arc_entity->end_angle;
}
