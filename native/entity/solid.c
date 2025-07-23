#include <jni.h>
#include <stdio.h>
#include "solid.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>

#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL) {
        return;
    }
    solid_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setElevation(JNIEnv *env, jobject obj, jlong ref, jdouble elevation) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL) {
        return;
    }
    solid_entity->elevation = elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner1(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL || point == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    if (xField == NULL || yField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, point, xField);
    jdouble y = (*env)->GetDoubleField(env, point, yField);
    solid_entity->corner1.x = x;
    solid_entity->corner1.y = y;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner2(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL || point == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    if (xField == NULL || yField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, point, xField);
    jdouble y = (*env)->GetDoubleField(env, point, yField);
    solid_entity->corner2.x = x;
    solid_entity->corner2.y = y;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner3(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL || point == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    if (xField == NULL || yField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, point, xField);
    jdouble y = (*env)->GetDoubleField(env, point, yField);
    solid_entity->corner3.x = x;
    solid_entity->corner3.y = y;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL || extrusion == NULL) {
        return;
    }
    jclass vectorCls = (*env)->GetObjectClass(env, extrusion);
    if (vectorCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorCls, "z", "D");
    if (xField == NULL || yField == NULL || zField == NULL) {
        (*env)->DeleteLocalRef(env, vectorCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, extrusion, xField);
    jdouble y = (*env)->GetDoubleField(env, extrusion, yField);
    jdouble z = (*env)->GetDoubleField(env, extrusion, zField);
    solid_entity->extrusion.x = x;
    solid_entity->extrusion.y = y;
    solid_entity->extrusion.z = z;
    (*env)->DeleteLocalRef(env, vectorCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Solid_setCorner4(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL || point == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, point);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    if (xField == NULL || yField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, point, xField);
    jdouble y = (*env)->GetDoubleField(env, point, yField);
    solid_entity->corner4.x = x;
    solid_entity->corner4.y = y;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Solid_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL) {
        return 0;
    }
    return solid_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Solid_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL) {
        return NULL;
    }
    jclass vectorCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, vectorCls, "<init>", "(DDD)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, vectorCls);
        return NULL;
    }
    jobject vectorObj = (*env)->NewObject(env, vectorCls, constructor, 
        solid_entity->extrusion.x,
        solid_entity->extrusion.y,
        solid_entity->extrusion.z);
    if (vectorObj == NULL) {
        (*env)->DeleteLocalRef(env, vectorCls);
        return NULL;
    }
    (*env)->DeleteLocalRef(env, vectorCls);
    return vectorObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Solid_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SOLID *solid_entity = (Dwg_Entity_SOLID*)(intptr_t)ref;
    if (solid_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)solid_entity->parent;
}
