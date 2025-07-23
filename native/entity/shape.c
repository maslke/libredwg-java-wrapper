#include <dwg.h>
#include <jni.h>
#include <stdio.h>
#include "shape.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>

#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setInsPt(JNIEnv *env, jobject obj, jlong ref, jobject insPt) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL || insPt == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, insPt);
    if (pointCls == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    if (xField == NULL || yField == NULL || zField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return;
    }
    jdouble x = (*env)->GetDoubleField(env, insPt, xField);
    jdouble y = (*env)->GetDoubleField(env, insPt, yField);
    jdouble z = (*env)->GetDoubleField(env, insPt, zField);
    shape_entity->ins_pt.x = x;
    shape_entity->ins_pt.y = y;
    shape_entity->ins_pt.z = z;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setScale(JNIEnv *env, jobject obj, jlong ref, jdouble scale) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->scale = scale;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setRotation(JNIEnv *env, jobject obj, jlong ref, jdouble rotation) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setWidthFactor(JNIEnv *env, jobject obj, jlong ref, jdouble widthFactor) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->width_factor = widthFactor;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setObliqueAngle(JNIEnv *env, jobject obj, jlong ref, jdouble obliqueAngle) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->oblique_angle = obliqueAngle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setStyleId(JNIEnv *env, jobject obj, jlong ref, jint styleId) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return;
    }
    shape_entity->style_id = styleId;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setStyle(JNIEnv *env, jobject obj, jlong ref, jobject style) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL || style == NULL) {
        return;
    }
    jclass styleCls = (*env)->GetObjectClass(env, style);
    if (styleCls == NULL) {
        return;
    }
    jmethodID refMethod = (*env)->GetMethodID(env, styleCls, "getRef", "()J");
    if (refMethod == NULL) {
        (*env)->DeleteLocalRef(env, styleCls);
        return;
    }
    jlong styleRef = (*env)->CallLongMethod(env, style, refMethod);
    Dwg_Object_Ref *styleEntity = (Dwg_Object_Ref*)(intptr_t)styleRef;
    if (styleEntity == NULL) {
        (*env)->DeleteLocalRef(env, styleCls);
        return;
    }
    shape_entity->style = (Dwg_Object_Ref*)(intptr_t)styleEntity;
    (*env)->DeleteLocalRef(env, styleCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Shape_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL || extrusion == NULL) {
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
    shape_entity->extrusion.x = x;
    shape_entity->extrusion.y = y;
    shape_entity->extrusion.z = z;
    (*env)->DeleteLocalRef(env, vectorCls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getInsPt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return NULL;
    }
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);
    if (pointObj == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        return NULL;
    }

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    if (xField == NULL || yField == NULL || zField == NULL) {
        (*env)->DeleteLocalRef(env, pointCls);
        (*env)->DeleteLocalRef(env, pointObj);
        return NULL;
    }
    (*env)->SetDoubleField(env, pointObj, xField, shape_entity->ins_pt.x);
    (*env)->SetDoubleField(env, pointObj, yField, shape_entity->ins_pt.y);
    (*env)->SetDoubleField(env, pointObj, zField, shape_entity->ins_pt.z);
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getScale(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->scale;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getRotation(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->rotation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getWidthFactor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->width_factor;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getObliqueAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->oblique_angle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Shape_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->thickness;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Shape_getStyleId(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return shape_entity->style_id;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getStyle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *style = shape_entity->style;
    if (style == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, style);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Shape_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
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
    jobject vectorObj = (*env)->NewObject(env, vectorCls, constructor, shape_entity->extrusion.x, shape_entity->extrusion.y, shape_entity->extrusion.z);
    if (vectorObj == NULL) {
        (*env)->DeleteLocalRef(env, vectorCls);
        return NULL;
    }
    (*env)->DeleteLocalRef(env, vectorCls);
    return vectorObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Shape_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_SHAPE *shape_entity = (Dwg_Entity_SHAPE*)(intptr_t)ref;
    if (shape_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)shape_entity->parent;
}
