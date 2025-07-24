#include <jni.h>
#include <stdio.h>
#include "mlinevertex.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setVertex(JNIEnv *env, jobject obj, jlong ref, jobject vertex) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL || vertex == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, vertex);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    mline_vertex->vertex.x = (*env)->CallDoubleMethod(env, vertex, getX);
    mline_vertex->vertex.y = (*env)->CallDoubleMethod(env, vertex, getY);
    mline_vertex->vertex.z = (*env)->CallDoubleMethod(env, vertex, getZ);
    (*env)->DeleteLocalRef(env, cls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    jmethodID init = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    jobject point = (*env)->NewObject(env, pointClass, init, 
                                      mline_vertex->vertex.x, 
                                      mline_vertex->vertex.y, 
                                      mline_vertex->vertex.z);
    (*env)->DeleteLocalRef(env, pointClass);
    return point;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setVertexDirection(JNIEnv *env, jobject obj, jlong ref, jobject vertexDirection) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL || vertexDirection == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, vertexDirection);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    mline_vertex->vertex_direction.x = (*env)->CallDoubleMethod(env, vertexDirection, getX);
    mline_vertex->vertex_direction.y = (*env)->CallDoubleMethod(env, vertexDirection, getY);
    mline_vertex->vertex_direction.z = (*env)->CallDoubleMethod(env, vertexDirection, getZ);
    (*env)->DeleteLocalRef(env, cls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getVertexDirection(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    jmethodID init = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    jobject vector = (*env)->NewObject(env, vectorClass, init, 
                                       mline_vertex->vertex_direction.x, 
                                       mline_vertex->vertex_direction.y, 
                                       mline_vertex->vertex_direction.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setMiterDirection(JNIEnv *env, jobject obj, jlong ref, jobject miterDirection) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL || miterDirection == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, miterDirection);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    mline_vertex->miter_direction.x = (*env)->CallDoubleMethod(env, miterDirection, getX);
    mline_vertex->miter_direction.y = (*env)->CallDoubleMethod(env, miterDirection, getY);
    mline_vertex->miter_direction.z = (*env)->CallDoubleMethod(env, miterDirection, getZ);
    (*env)->DeleteLocalRef(env, cls);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getMiterDirection(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    jmethodID init = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    jobject vector = (*env)->NewObject(env, vectorClass, init, 
                                       mline_vertex->miter_direction.x, 
                                       mline_vertex->miter_direction.y, 
                                       mline_vertex->miter_direction.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setNumLines(JNIEnv *env, jobject obj, jlong ref, jlong numLines) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return;
    }
    mline_vertex->num_lines = (BITCODE_RC)numLines;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getNumLines(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return 0;
    }
    return (jlong)mline_vertex->num_lines;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_setLines(JNIEnv *env, jobject obj, jlong ref, jobject lines) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL || lines == NULL) {
        return;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/List");
    jmethodID get = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID size = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint length = (*env)->CallIntMethod(env, lines, size);
    
    if (mline_vertex->lines) {
        free(mline_vertex->lines);
    }
    mline_vertex->lines = (Dwg_MLINE_line*)malloc(length * sizeof(Dwg_MLINE_line));
    mline_vertex->num_lines = (BITCODE_RC)length;
    
    for (jint i = 0; i < length; i++) {
        jobject lineObj = (*env)->CallObjectMethod(env, lines, get, i);
        
        jclass lineClass = (*env)->GetObjectClass(env, lineObj);
        jfieldID refField = (*env)->GetFieldID(env, lineClass, "ref", "J");
        jlong lineRef = (*env)->GetLongField(env, lineObj, refField);
        
        if (lineRef != 0) {
            Dwg_MLINE_line *source_line = (Dwg_MLINE_line*)(intptr_t)lineRef;
            mline_vertex->lines[i] = *source_line;
            mline_vertex->lines[i].parent = mline_vertex;
        }
        
        (*env)->DeleteLocalRef(env, lineObj);
        (*env)->DeleteLocalRef(env, lineClass);
    }
    (*env)->DeleteLocalRef(env, listClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getLines(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL || mline_vertex->lines == NULL) {
        return NULL;
    }
    
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID listInit = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listClass, listInit);
    jmethodID add = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    
    jclass lineClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/component/MLineLine");
    jmethodID lineInit = (*env)->GetMethodID(env, lineClass, "<init>", "(J)V");
    
    for (int i = 0; i < mline_vertex->num_lines; i++) {
        jlong lineRef = (jlong)(intptr_t)&(mline_vertex->lines[i]);
        jobject lineObj = (*env)->NewObject(env, lineClass, lineInit, lineRef);
        (*env)->CallBooleanMethod(env, list, add, lineObj);
        (*env)->DeleteLocalRef(env, lineObj);
    }
    
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, lineClass);
    return list;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_component_MLineVertex_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_MLINE_vertex *mline_vertex = (Dwg_MLINE_vertex*)(intptr_t)ref;
    if (mline_vertex == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)mline_vertex->parent;
}
