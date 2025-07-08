#include <jni.h>
#include <stdio.h>
#include "line.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setStartNative(JNIEnv *env, jobject obj, jlong ref, jobject start) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    jclass start_class = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, start_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, start_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, start_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, start, fidX);
    jdouble y = (*env)->GetDoubleField(env, start, fidY);
    jdouble z = (*env)->GetDoubleField(env, start, fidZ);
    BITCODE_3BD s = {.x = x, .y = y, .z = z};
    line_entity->start = s;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Line_setEndNative(JNIEnv *env, jobject obj, jlong ref, jobject end) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    jclass end_class = (*env)->GetObjectClass(env, end);
    jfieldID fidX = (*env)->GetFieldID(env, end_class, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, end_class, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, end_class, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, end, fidX);
    jdouble y = (*env)->GetDoubleField(env, end, fidY);
    jdouble z = (*env)->GetDoubleField(env, end, fidZ);
    BITCODE_3BD e = {.x = x, .y = y, .z = z};
    line_entity->end = e;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Line_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_LINE *line_entity = (Dwg_Entity_LINE*)(intptr_t)ref;
    return (intptr_t)line_entity->parent;
}
