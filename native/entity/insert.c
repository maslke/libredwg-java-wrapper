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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setInsPt(JNIEnv *env, jobject obj, jlong ref, jobject pt) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    insert_entity->ins_pt.x = (*env)->GetDoubleField(env, pt, xField);
    insert_entity->ins_pt.y = (*env)->GetDoubleField(env, pt, yField);
    insert_entity->ins_pt.z = (*env)->GetDoubleField(env, pt, zField);
    (*env)->DeleteLocalRef(env, pointClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScaleFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->scale_flag = flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setScale(JNIEnv *env, jobject job, jlong ref, jobject scale) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    insert_entity->scale.x = (*env)->GetDoubleField(env, scale, xField);
    insert_entity->scale.y = (*env)->GetDoubleField(env, scale, yField);
    insert_entity->scale.z = (*env)->GetDoubleField(env, scale, zField);
    (*env)->DeleteLocalRef(env, pointClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRotation(JNIEnv *env, jobject job, jlong ref, jdouble rotation) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    insert_entity->extrusion.x = (*env)->GetDoubleField(env, extrusion, xField);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setHasAttribs(JNIEnv *env, jobject job, jlong ref, jint has_attribs) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->has_attribs = has_attribs;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumOwned(JNIEnv *env, jobject job, jlong ref, jint num_owned) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->num_owned = num_owned;
}
