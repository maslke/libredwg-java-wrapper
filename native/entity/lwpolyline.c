#include <jni.h>
#include <stdio.h>
#include "lwpolyline.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setFlagNative(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->flag = flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setConstWidthNative(JNIEnv *env, jobject obj, jlong ref, jdouble const_width) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->const_width = const_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setElevationNative(JNIEnv *env, jobject obj, jlong ref, jdouble elevation) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->elevation = elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setThicknessNative(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setExtrusionNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->extrusion.x = x;
    lwpolyline_entity->extrusion.y = y;
    lwpolyline_entity->extrusion.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumPointsNative(JNIEnv *env, jobject obj, jlong ref, jint num_points) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline_entity->num_points = num_points;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setBulgesNative(JNIEnv *env, jobject job, jlong ref, jobject bulgeList) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    jclass listClass = (*env)->GetObjectClass(env, bulgeList);
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, bulgeList, sizeMethod);
    if (size <= 0) {
        return;
    }
    BITCODE_BD *bulges = malloc(sizeof(BITCODE_BD) * size);
    if (bulges == NULL) {
        return;
    }
    jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
    jmethodID doubleValueMethod = (*env)->GetMethodID(env, doubleClass, "doubleValue", "()D");
    for (int i = 0; i < size; ++i) {
        jobject bulgeObject = (*env)->CallObjectMethod(env, bulgeList, getMethod, i);
        jdouble val = (*env)->CallDoubleMethod(env, bulgeObject, doubleValueMethod);
        bulges[i] = val;

    }

    lwpolyline_entity->bulges = bulges;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setWidthsNative(JNIEnv *env, jobject job, jlong ref, jobject widthsList) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    if (lwpolyline_entity == NULL) {
        return;
    }
    jclass listClass = (*env)->GetObjectClass(env, widthsList);
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, widthsList, sizeMethod);
    if (size <= 0) {
        return;
    }
    jclass widthClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/component/LwpolylineWidth");
    jfieldID startField = (*env)->GetFieldID(env, widthClass, "start", "D");
    jfieldID endField = (*env)->GetFieldID(env, widthClass, "end", "D");
    Dwg_LWPOLYLINE_width *widths = malloc(sizeof(Dwg_LWPOLYLINE_width) * size);
    if (widths == NULL) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        jobject widthObject = (*env)->CallObjectMethod(env, widthsList, getMethod, i);
        if (widthObject != NULL) {
            jdouble start = (*env)->GetDoubleField(env, widthObject, startField);
            jdouble end = (*env)->GetDoubleField(env, widthObject, endField);
            widths[i].start = start;
            widths[i].end = end;
        }
        else {
            widths[i].start = 0.0;
            widths[i].end = 0.0;
        }
    }

    lwpolyline_entity->widths = widths;
    lwpolyline_entity->num_widths = size;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setPointsNative(JNIEnv *env, jobject obj, jlong ref, jobject pointList) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    jclass listClass = (*env)->GetObjectClass(env, pointList);
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, pointList, sizeMethod);
    if (size <= 0) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    BITCODE_2RD *pnts = malloc(sizeof(BITCODE_2RD) * size);
    for (int i = 0; i < size; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        if (pointObj != NULL) {
            jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
            jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
            pnts[i] = (BITCODE_2RD){ x, y };
        }
        else {
            pnts[i] = (BITCODE_2RD) { 0, 0 };
        }
    }

    lwpolyline_entity->points = pnts;
    lwpolyline_entity->num_points = size;
    lwpolyline_entity->num_vertexids = size;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumBulgesNative(JNIEnv *env, jobject job, jlong ref, jint num_bulges) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    lwpolyline->num_bulges = num_bulges;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return (jlong)(intptr_t)lwpolyline->parent;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getFlagNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->flag;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->thickness;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getConstWidthNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->const_width;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumPointsNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->num_points;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumVertexidsNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->num_vertexids;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getElevationNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->elevation;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, vectorClass, "<init>", "()V");
    jobject vectorObj = (*env)->NewObject(env, vectorClass, constructor);

    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    (*env)->SetDoubleField(env, vectorObj, xField, lwpolyline->extrusion.x);
    (*env)->SetDoubleField(env, vectorObj, yField, lwpolyline->extrusion.y);
    (*env)->SetDoubleField(env, vectorObj, zField, lwpolyline->extrusion.z);
    return vectorObj;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumBulgesNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    return lwpolyline->num_bulges;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getPointsNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;

    if (lwpolyline == NULL || lwpolyline->points == NULL || lwpolyline->num_points <= 0) {
        return NULL;
    }

    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID listConstructor = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jmethodID addMethod = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");

    jobject listObj = (*env)->NewObject(env, listClass, listConstructor);

    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    jmethodID constructor = (*env)->GetMethodID(env, pointClass, "<init>", "()V");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");

    BITCODE_2RD *pnts = lwpolyline->points;

    for (int i = 0; i < lwpolyline->num_points; i++) {
        jobject pointObj = (*env)->NewObject(env, pointClass, constructor);
        (*env)->SetDoubleField(env, pointObj, xField, pnts[i].x);
        (*env)->SetDoubleField(env, pointObj, yField, pnts[i].y);
        (*env)->CallBooleanMethod(env, listObj, addMethod, pointObj);
    }

    return listObj;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setNumVertexidsNative(JNIEnv *env, jobject job, jlong ref, jint num_vertexids) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    if (lwpolyline == NULL) {
        return;
    }
    lwpolyline->num_vertexids = num_vertexids;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getNumWidthsNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    if (lwpolyline == NULL) {
        return 0;
    }
    return lwpolyline->num_widths;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_getWidthsNative(JNIEnv *env, jobject job, jlong ref) {

    Dwg_Entity_LWPOLYLINE *lwpolyline = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;

    if (lwpolyline == NULL || lwpolyline->points == NULL || lwpolyline->num_points <= 0) {
        return NULL;
    }

    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID listConstructor = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jmethodID addMethod = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");

    jobject listObj = (*env)->NewObject(env, listClass, listConstructor);

    jclass widthClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/component/LwpolylineWidth");
    jmethodID constructor = (*env)->GetMethodID(env, widthClass, "<init>", "()V");
    jfieldID startField = (*env)->GetFieldID(env, widthClass, "start", "D");
    jfieldID endField = (*env)->GetFieldID(env, widthClass, "end", "D");

    Dwg_LWPOLYLINE_width *widths = lwpolyline->widths;

    for (int i = 0; i < lwpolyline->num_widths; i++) {
        jobject widthObj = (*env)->NewObject(env, widthClass, constructor);
        (*env)->SetDoubleField(env, widthObj, startField, widths[i].start);
        (*env)->SetDoubleField(env, widthObj, endField, widths[i].end);
        (*env)->CallBooleanMethod(env, listObj, addMethod, widthObj);
    }

    return listObj;
}


