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
#include "cjson/cJSON.h"
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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Lwpolyline_setPointsNative(JNIEnv *env, jobject obj, jlong ref, jobject pointList) {
    Dwg_Entity_LWPOLYLINE *lwpolyline_entity = (Dwg_Entity_LWPOLYLINE*)(intptr_t)ref;
    jclass listClass = (*env)->GetObjectClass(env, pointList);
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, pointList, sizeMethod);
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    BITCODE_2RD *pnts = malloc(sizeof(BITCODE_2RD) * size);
    for (int i = 0; i < size; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        pnts[i] = (BITCODE_2RD){ x, y };
    }

    lwpolyline_entity->points = pnts;
}

