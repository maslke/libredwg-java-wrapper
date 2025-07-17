#include <jni.h>
#include <stdio.h>
#include "insert.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setInsPtNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    Dwg_Bitcode_3BD ins_pt = {.x = x, .y = y, .z = z};
    insert_entity->ins_pt = ins_pt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleFlagNative(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    insert_entity->scale_flag = flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleNative(JNIEnv *env, jobject job, jlong ref, jdouble scale_x, jdouble scale_y, jdouble scale_z) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    Dwg_Bitcode_3BD scale = {.x = scale_x, .y = scale_y, .z = scale_z};
    insert_entity->scale = scale;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRotationNative(JNIEnv *env, jobject job, jlong ref, jdouble rotation) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    insert_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setExtrusionNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    Dwg_Bitcode_3BD extrusion = {.x = x, .y = y, .z = z};
    insert_entity->extrusion = extrusion;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setHasAttribsNative(JNIEnv *env, jobject job, jlong ref, jint has_attribs) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    insert_entity->has_attribs = has_attribs;
}
