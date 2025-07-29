#include <jni.h>
#include <stdio.h>
#include "polyline2d.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setHasVertex(JNIEnv *env, jobject obj, jlong ref, jint hasVertex) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->has_vertex = hasVertex;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getHasVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->has_vertex;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumOwned(JNIEnv *env, jobject obj, jlong ref, jlong num_owned) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->num_owned = num_owned;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumOwned(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->num_owned;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setFirstVertex(JNIEnv *env, jobject obj, jlong ref, jobject firstVertex) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || firstVertex == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, firstVertex);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong vertexRef = (*env)->GetLongField(env, firstVertex, refField);
    polyline2d->first_vertex = (Dwg_Object_Ref*)(intptr_t)vertexRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getFirstVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || polyline2d->first_vertex == NULL) {
        return NULL;
    }

    return createDwgObjectRef(env, polyline2d->first_vertex);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setLastVertex(JNIEnv *env, jobject obj, jlong ref, jobject lastVertex) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || lastVertex == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, lastVertex);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong vertexRef = (*env)->GetLongField(env, lastVertex, refField);
    polyline2d->last_vertex = (Dwg_Object_Ref*)(intptr_t)vertexRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getLastVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || polyline2d->last_vertex == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, polyline2d->last_vertex);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)polyline2d->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setVertex(JNIEnv *env, jobject obj, jlong ref, jobject vertexList) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || vertexList == NULL) {
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

    if (polyline2d->vertex != NULL) {
        free(polyline2d->vertex);
    }
    polyline2d->vertex = vertex;

    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getVertex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || polyline2d->vertex == NULL) {
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

    BITCODE_H *pointer = polyline2d->vertex;
    jint size = sizeof(pointer) / sizeof(BITCODE_H);
    for (int i = 0; i < size; i++) {
        jobject refObj = createDwgObjectRef(env, polyline2d->vertex[i]);
        (*env)->CallBooleanMethod(env, listObj, addMethod, refObj);
    }

    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, refClass);

    return listObj;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setSeqend(JNIEnv *env, jobject obj, jlong ref, jobject seqend) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || seqend == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, seqend);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong seqendRef = (*env)->GetLongField(env, seqend, refField);
    polyline2d->seqend = (Dwg_Object_Ref*)(intptr_t)seqendRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getSeqend(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || polyline2d->seqend == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, polyline2d->seqend);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->flag = flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setCurveType(JNIEnv *env, jobject obj, jlong ref, jint curveType) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->curve_type = curveType;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getCurveType(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->curve_type;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setStartWidth(JNIEnv *env, jobject obj, jlong ref, jdouble startWidth) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->start_width = startWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getStartWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0.0;
    }
    return polyline2d->start_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setEndWidth(JNIEnv *env, jobject obj, jlong ref, jdouble endWidth) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->end_width = endWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getEndWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0.0;
    }
    return polyline2d->end_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setThickness(JNIEnv *env, jobject obj, jlong ref, jdouble thickness) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->thickness = thickness;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getThickness(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0.0;
    }
    return polyline2d->thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setElevation(JNIEnv *env, jobject obj, jlong ref, jdouble elevation) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->elevation = elevation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getElevation(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0.0;
    }
    return polyline2d->elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || extrusion == NULL) {
        return;
    }
    jclass vectorClass = (*env)->GetObjectClass(env, extrusion);
    if (vectorClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");

    polyline2d->extrusion.x = (*env)->GetDoubleField(env, extrusion, xField);
    polyline2d->extrusion.y = (*env)->GetDoubleField(env, extrusion, yField);
    polyline2d->extrusion.z = (*env)->GetDoubleField(env, extrusion, zField);

    (*env)->DeleteLocalRef(env, vectorClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtrusion(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return NULL;
    }

    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    jmethodID constructor = (*env)->GetMethodID(env, vectorClass, "<init>", "()V");
    jobject vectorObj = (*env)->NewObject(env, vectorClass, constructor);

    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorClass, "z", "D");

    (*env)->SetDoubleField(env, vectorObj, xField, polyline2d->extrusion.x);
    (*env)->SetDoubleField(env, vectorObj, yField, polyline2d->extrusion.y);
    (*env)->SetDoubleField(env, vectorObj, zField, polyline2d->extrusion.z);

    (*env)->DeleteLocalRef(env, vectorClass);
    return vectorObj;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtraR11Size(JNIEnv *env, jobject obj, jlong ref, jlong extraR11Size) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->extra_r11_size = extraR11Size;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtraR11Size(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->extra_r11_size;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setExtraR11Text(JNIEnv *env, jobject obj, jlong ref, jstring extraR11Text) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || extraR11Text == NULL) {
        return;
    }
    const char *text = (*env)->GetStringUTFChars(env, extraR11Text, NULL);
    if (polyline2d->extra_r11_text != NULL) {
        free(polyline2d->extra_r11_text);
    }
    polyline2d->extra_r11_text = strdup(text);
    (*env)->ReleaseStringUTFChars(env, extraR11Text, text);
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getExtraR11Text(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL || polyline2d->extra_r11_text == NULL) {
        return NULL;
    }
    return (*env)->NewStringUTF(env, polyline2d->extra_r11_text);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumMVerts(JNIEnv *env, jobject obj, jlong ref, jint numMVerts) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->num_m_verts = numMVerts;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumMVerts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->num_m_verts;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_setNumNVerts(JNIEnv *env, jobject obj, jlong ref, jint numNVerts) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return;
    }
    polyline2d->num_n_verts = numNVerts;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Polyline2d_getNumNVerts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_POLYLINE_2D *polyline2d = (Dwg_Entity_POLYLINE_2D*)(intptr_t)ref;
    if (polyline2d == NULL) {
        return 0;
    }
    return polyline2d->num_n_verts;
}
