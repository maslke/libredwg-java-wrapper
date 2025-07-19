#include <jni.h>
#include <stdio.h>
#include "blockheader.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPoint(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, point);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d pt = {.x = x, .y = y, .z = z};
    Dwg_Entity_POINT *point_entity =  dwg_add_POINT(hdr, &pt);
    jlong reference = (jlong)(intptr_t)point_entity;
    if (reference == 0) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Point");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointClass, "<init>", "(J)V");
    jobject pointObj = (*env)->NewObject(env, pointClass, constructor, reference);
    return pointObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLineNative(JNIEnv *env, jobject obj, jlong ref,
jobject start, jobject end) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble start_x = (*env)->GetDoubleField(env, start, fidX);
    jdouble start_y = (*env)->GetDoubleField(env, start, fidY);
    jdouble start_z = (*env)->GetDoubleField(env, start, fidZ);

    dwg_point_3d start_point = {.x = start_x, .y = start_y, .z = start_z};

    jdouble end_x = (*env)->GetDoubleField(env, end, fidX);
    jdouble end_y = (*env)->GetDoubleField(env, end, fidY);
    jdouble end_z = (*env)->GetDoubleField(env, end, fidZ);
    dwg_point_3d end_point = {.x = end_x, .y = end_y, .z = end_z};
    Dwg_Entity_LINE *line_entity = dwg_add_LINE(hdr, &start_point, &end_point);
    return (jlong)(intptr_t)line_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addTextNative(JNIEnv *env, jobject job, jlong ref, jstring text_value, jobject ins_pt, jdouble height) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char *chars = (*env)->GetStringUTFChars(env, text_value, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    jclass clazz = (*env)->GetObjectClass(env, ins_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble ins_x = (*env)->GetDoubleField(env, ins_pt, fidX);
    jdouble ins_y = (*env)->GetDoubleField(env, ins_pt, fidY);
    jdouble ins_z = (*env)->GetDoubleField(env, ins_pt, fidZ);

    dwg_point_3d insert_pt = { .x = ins_x, .y = ins_y, .z = ins_z };
    Dwg_Entity_TEXT *text_entity = dwg_add_TEXT(hdr, strdup(gbk_text), &insert_pt, height);
    return (jlong)(intptr_t)text_entity;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircle(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_CIRCLE *circle_entity = dwg_add_CIRCLE(hdr, &center_pt, radius);
    jlong reference = (jlong)(intptr_t)circle_entity;
    jclass circleClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Circle");
    if (circleClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, circleClass, "<init>", "(J)V");
    jobject circleObj = (*env)->NewObject(env, circleClass, constructor, reference);
    return circleObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArc(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius, jdouble start_angle, jdouble end_angle) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ARC *arc_entity = dwg_add_ARC(hdr, &center_pt, radius, start_angle, end_angle);
    jlong reference = (jlong)(intptr_t)arc_entity;

    jclass arcClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Arc");
    if (arcClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, arcClass, "<init>", "(J)V");
    jobject arcObj = (*env)->NewObject(env, arcClass, constructor, reference);
    return arcObj;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipseNative(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble majorAxis, jdouble axisRatio) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ELLIPSE *ellipse_entity = dwg_add_ELLIPSE(hdr, &center_pt, majorAxis, axisRatio);
    return (jlong)(intptr_t)ellipse_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addInsertNative(JNIEnv *env, jobject job, jlong ref, jobject insert_pt, jstring block_name, jdouble scale_x, jdouble scale_y, jdouble scale_z, jdouble rotation) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, insert_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, insert_pt, fidX);
    jdouble y = (*env)->GetDoubleField(env, insert_pt, fidY);
    jdouble z = (*env)->GetDoubleField(env, insert_pt, fidZ);
    dwg_point_3d ins_pt = {.x = x, .y = y, .z = z};
    const char* chars = (*env)->GetStringUTFChars(env, block_name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Entity_INSERT *insert_entity = dwg_add_INSERT(hdr, &ins_pt, chars, scale_x, scale_y, scale_z, rotation);
    (*env)->ReleaseStringUTFChars(env, block_name, chars);
    return (jlong)(intptr_t)insert_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addBlockNative(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Entity_BLOCK *block = dwg_add_BLOCK(hdr, chars);
    (*env)->ReleaseStringUTFChars(env, name, chars);
    return (jlong)(intptr_t)block;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEndBlkNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    Dwg_Entity_ENDBLK *endblk_entity = dwg_add_ENDBLK(hdr);
    return (jlong)(intptr_t)endblk_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLwpolylineNative(JNIEnv *env, jobject job, jlong ref, jint num_points, jobject pointList) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass listClass = (*env)->GetObjectClass(env, pointList);
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    dwg_point_2d *pnts = malloc(sizeof(dwg_point_2d) * num_points);
    for (int i = 0; i < num_points; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        pnts[i].x = x;
        pnts[i].y = y;
    }
    Dwg_Entity_LWPOLYLINE *lwpolyline = dwg_add_LWPOLYLINE(hdr, num_points, pnts);
    return (jlong)(intptr_t)lwpolyline;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addRay(JNIEnv *env, jobject job, jlong ref, jobject point, jobject vector) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return NULL;
    }
    if (vector == NULL) {
        return NULL;
    }

    jclass clazz = (*env)->GetObjectClass(env, point);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d pt = {.x = x, .y = y, .z = z};
    jclass vectorClass = (*env)->GetObjectClass(env, vector);
    jfieldID vectorXField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID vectorYField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID vectorZField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble vectorX = (*env)->GetDoubleField(env, vector, vectorXField);
    jdouble vectorY = (*env)->GetDoubleField(env, vector, vectorYField);
    jdouble vectorZ = (*env)->GetDoubleField(env, vector, vectorZField);
    dwg_point_3d vec = {.x = vectorX, .y = vectorY, .z = vectorZ};
    Dwg_Entity_RAY *ray = dwg_add_RAY(hdr, &pt, &vec);
    jlong reference = (jlong)(intptr_t)ray;
    if (reference == 0) {
        return NULL;
    }
    jclass rayClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Ray");
    if (rayClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, rayClass, "<init>", "(J)V");
    jobject rayObj = (*env)->NewObject(env, rayClass, constructor, reference);
    return rayObj;
}