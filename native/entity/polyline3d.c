#include <jni.h>
#include <stdio.h>
#include "polyline3d.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setHasVertex(JNIEnv *env, jobject obj, jlong ref, jint hasVertex) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->has_vertex = hasVertex;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getHasVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0;
    }
    return polyline3d->has_vertex;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setNumVertex(JNIEnv *env, jobject obj, jlong ref, jlong numVertex) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->num_owned = numVertex;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getNumVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0;
    }
    return polyline3d->num_owned;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setFirstVertex(JNIEnv *env, jobject obj, jlong ref, jobject firstVertex) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || firstVertex == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, firstVertex);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong vertexRef = (*env)->GetLongField(env, firstVertex, refField);
    polyline3d->first_vertex = (Dwg_Object_Ref*)(intptr_t)vertexRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getFirstVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || polyline3d->first_vertex == NULL) {
        return NULL;
    }

    return createDwgObjectRef(env, polyline3d->first_vertex);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setLastVertex(JNIEnv *env, jobject obj, jlong ref, jobject lastVertex) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || lastVertex == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, lastVertex);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong vertexRef = (*env)->GetLongField(env, lastVertex, refField);
    polyline3d->last_vertex = (Dwg_Object_Ref*)(intptr_t)vertexRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getLastVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || polyline3d->last_vertex == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, polyline3d->last_vertex);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)polyline3d->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setVertex(JNIEnv *env, jobject obj, jlong ref, jobject vertexList) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || vertexList == NULL) {
        return;
    }

    jclass listClass = (*env)->GetObjectClass(env, vertexList);
    if (listClass == NULL) {
        return;
    }

    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, vertexList, sizeMethod);

    if (size <= 0) {
        return;
    }

    Dwg_Object_Ref **vertex = malloc(sizeof(Dwg_Object_Ref*) * size);
    if (vertex == NULL) {
        return;
    }

    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return;
    }

    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");

    for (int i = 0; i < size; i++) {
        jobject vertexObj = (*env)->CallObjectMethod(env, vertexList, getMethod, i);
        if (vertexObj != NULL) {
            jlong vertexRef = (*env)->GetLongField(env, vertexObj, refField);
            vertex[i] = (Dwg_Object_Ref*)(intptr_t)vertexRef;
        } else {
            vertex[i] = NULL;
        }
    }

    if (polyline3d->vertex != NULL) {
        free(polyline3d->vertex);
    }
    polyline3d->vertex = vertex;

    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || polyline3d->vertex == NULL) {
        return NULL;
    }

    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }

    jmethodID listConstructor = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jmethodID addMethod = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");

    jobject listObj = (*env)->NewObject(env, listClass, listConstructor);

    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }

    jmethodID constructor = (*env)->GetMethodID(env, refClass, "<init>", "()V");
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");

    BITCODE_H *pointer = polyline3d->vertex;
    jint size = sizeof(pointer) / sizeof(BITCODE_H);
    for (int i = 0; i < size; i++) {
        jobject refObj = createDwgObjectRef(env, polyline3d->vertex[i]);
        (*env)->CallBooleanMethod(env, listObj, addMethod, refObj);
    }

    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, refClass);

    return listObj;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setSeqend(JNIEnv *env, jobject obj, jlong ref, jobject seqend) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || seqend == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, seqend);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong seqendRef = (*env)->GetLongField(env, seqend, refField);
    polyline3d->seqend = (Dwg_Object_Ref*)(intptr_t)seqendRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getSeqend(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || polyline3d->seqend == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, polyline3d->seqend);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->flag = flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0;
    }
    return polyline3d->flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setCurveType(JNIEnv *env, jobject obj, jlong ref, jint curveType) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->curve_type = curveType;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getCurveType(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0;
    }
    return polyline3d->curve_type;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setStartWidth(JNIEnv *env, jobject obj, jlong ref, jdouble startWidth) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->start_width = startWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getStartWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0.0;
    }
    return polyline3d->start_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setEndWidth(JNIEnv *env, jobject obj, jlong ref, jdouble endWidth) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return;
    }
    polyline3d->end_width = endWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getEndWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return 0.0;
    }
    return polyline3d->end_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL || extrusion == NULL) {
        return;
    }
    jclass vectorClass = (*env)->GetObjectClass(env, extrusion);
    if (vectorClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    
    polyline3d->extrusion.x = (*env)->GetDoubleField(env, extrusion, xField);
    polyline3d->extrusion.y = (*env)->GetDoubleField(env, extrusion, yField);
    polyline3d->extrusion.z = (*env)->GetDoubleField(env, extrusion, zField);
    
    (*env)->DeleteLocalRef(env, vectorClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline3d_getExtrusion(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_3D *polyline3d = (Dwg_Entity_POLYLINE_3D*)(intptr_t)ref;
    if (polyline3d == NULL) {
        return NULL;
    }
    
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    jmethodID constructor = (*env)->GetMethodID(env, vectorClass, "<init>", "()V");
    jobject vectorObj = (*env)->NewObject(env, vectorClass, constructor);
    
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    
    (*env)->SetDoubleField(env, vectorObj, xField, polyline3d->extrusion.x);
    (*env)->SetDoubleField(env, vectorObj, yField, polyline3d->extrusion.y);
    (*env)->SetDoubleField(env, vectorObj, zField, polyline3d->extrusion.z);
    
    (*env)->DeleteLocalRef(env, vectorClass);
    return vectorObj;
} 