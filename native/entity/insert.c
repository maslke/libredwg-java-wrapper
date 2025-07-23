#include <jni.h>
#include <stdio.h>
#include "insert.h"
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
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
    insert_entity->extrusion.y = (*env)->GetDoubleField(env, extrusion, yField);
    insert_entity->extrusion.z = (*env)->GetDoubleField(env, extrusion, zField);
    (*env)->DeleteLocalRef(env, vectorClass);
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


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setBlockHeader(JNIEnv *env, jobject job, jlong ref, jobject block_header) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass blockHeaderClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (blockHeaderClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, blockHeaderClass, "ref", "J");
    jlong blockHeaderRef = (*env)->GetLongField(env, block_header, refField);
    insert_entity->block_header = (Dwg_Object_Ref*)(intptr_t)blockHeaderRef;
    (*env)->DeleteLocalRef(env, blockHeaderClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setFirstAttrib(JNIEnv *env, jobject job, jlong ref, jobject first_attrib) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass attribClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (attribClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, attribClass, "ref", "J");
    jlong attribRef = (*env)->GetLongField(env, first_attrib, refField);
    insert_entity->first_attrib = (Dwg_Object_Ref*)(intptr_t)attribRef;
    (*env)->DeleteLocalRef(env, attribClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setLastAttrib(JNIEnv *env, jobject job, jlong ref, jobject last_attrib) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass attribClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (attribClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, attribClass, "ref", "J");
    jlong attribRef = (*env)->GetLongField(env, last_attrib, refField); 
    insert_entity->last_attrib = (Dwg_Object_Ref*)(intptr_t)attribRef;
    (*env)->DeleteLocalRef(env, attribClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setSeqend(JNIEnv *env, jobject job, jlong ref, jobject seqend) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass seqendClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (seqendClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, seqendClass, "ref", "J");
    jlong seqendRef = (*env)->GetLongField(env, seqend, refField);
    insert_entity->seqend = (Dwg_Object_Ref*)(intptr_t)seqendRef;
    (*env)->DeleteLocalRef(env, seqendClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setAttribs(JNIEnv *env, jobject job, jlong ref, jobject attribs) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    jclass attribListClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (attribListClass == NULL) {
        return;
    }
    jmethodID addMethod = (*env)->GetMethodID(env, attribListClass, "add", "(Ljava/lang/Object;)Z");
    jmethodID getMethod = (*env)->GetMethodID(env, attribListClass, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, attribListClass, "size", "()I");
    int size = (*env)->CallIntMethod(env, attribs, sizeMethod);
    BITCODE_H *attribsRef = malloc(sizeof(BITCODE_H) * size);
    jclass attribClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    jfieldID refField = (*env)->GetFieldID(env, attribClass, "ref", "J");
    if (attribClass == NULL) {
        free(attribsRef);
        (*env)->DeleteLocalRef(env, attribListClass);
        return;
    }
    for (int i = 0; i < size; i++) {
        jobject attrib = (*env)->CallObjectMethod(env, attribs, getMethod, i);
        if (attrib == NULL) {
            continue;
        }
        jlong attribRef = (*env)->GetLongField(env, attrib, refField);
        attribsRef[i] = (BITCODE_H)(intptr_t)attribRef;
    }
    insert_entity->attribs = attribsRef;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumCols(JNIEnv *env, jobject job, jlong ref, jint num_cols) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->num_cols = num_cols;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setNumRows(JNIEnv *env, jobject job, jlong ref, jint num_rows) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->num_rows = num_rows;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setColSpacing(JNIEnv *env, jobject job, jlong ref, jdouble col_spacing) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->col_spacing = col_spacing;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setRowSpacing(JNIEnv *env, jobject job, jlong ref, jdouble row_spacing) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    insert_entity->row_spacing = row_spacing;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Insert_setBlockName(JNIEnv *env, jobject job, jlong ref, jstring block_name) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return;
    }
    const char *chars = (*env)->GetStringUTFChars(env, block_name, NULL);
    char gbk_chars[256];
    utf8_to_gbk(chars, gbk_chars, sizeof(gbk_chars));
    insert_entity->block_name = strdup(gbk_chars);
    (*env)->ReleaseStringUTFChars(env, block_name, chars);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Insert_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)insert_entity->parent;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getInsPt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID pointConstructor = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    if (pointConstructor == NULL) {
        return NULL;
    }
    jobject pointObj = (*env)->NewObject(env, pointClass, pointConstructor, insert_entity->ins_pt.x, insert_entity->ins_pt.y, insert_entity->ins_pt.z);
    (*env)->DeleteLocalRef(env, pointClass);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getScale(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID pointConstructor = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    if (pointConstructor == NULL) {
        return NULL;
    }
    jobject pointObj = (*env)->NewObject(env, pointClass, pointConstructor, insert_entity->scale.x, insert_entity->scale.y, insert_entity->scale.z);
    (*env)->DeleteLocalRef(env, pointClass);
    return pointObj;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getScaleFlag(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return insert_entity->scale_flag;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getRotation(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0.0;
    }
    return insert_entity->rotation;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID vectorConstructor = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    if (vectorConstructor == NULL) {
        return NULL;
    }
    jobject vectorObj = (*env)->NewObject(env, vectorClass, vectorConstructor, insert_entity->extrusion.x, insert_entity->extrusion.y, insert_entity->extrusion.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vectorObj;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getHasAttribs(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return insert_entity->has_attribs;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumOwned(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return insert_entity->num_owned;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getBlockHeader(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *block_header = insert_entity->block_header;
    if (block_header == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, block_header);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getFirstAttrib(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *first_attrib = insert_entity->first_attrib;
    if (first_attrib == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, first_attrib);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getLastAttrib(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *last_attrib = insert_entity->last_attrib;
    if (last_attrib == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, last_attrib);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getSeqend(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;   
    if (insert_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *seqend = insert_entity->seqend;
    if (seqend == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, seqend);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Insert_getAttribs(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return NULL;
    }
    BITCODE_H *attribs = insert_entity->attribs;
    if (attribs == NULL) {
        return NULL;
    }
    jclass attribListClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (attribListClass == NULL) {
        return NULL;
    }
    jmethodID addMethod = (*env)->GetMethodID(env, attribListClass, "add", "(Ljava/lang/Object;)Z");
    jmethodID listConstructor = (*env)->GetMethodID(env, attribListClass, "<init>", "()V");
    jobject attribList = (*env)->NewObject(env, attribListClass, listConstructor);
    if (attribList == NULL) {
        return NULL;
    }

    jint size = sizeof(attribs) / sizeof(BITCODE_H);
    jclass attribClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (attribClass == NULL) {
        (*env)->DeleteLocalRef(env, attribListClass);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, attribClass, "<init>", "(J)V");
    jfieldID refField = (*env)->GetFieldID(env, attribClass, "ref", "J");

    for (int i = 0; i < size; i++) {
        jobject attrib = (*env)->NewObject(env, attribClass, constructor, (Dwg_Object_Ref*)(intptr_t)attribs[i]);
        if (attrib == NULL) {
            continue;
        }
        (*env)->CallBooleanMethod(env, attribList, addMethod, attrib);
    }
    (*env)->DeleteLocalRef(env, attribListClass);
    (*env)->DeleteLocalRef(env, attribClass);
    return attribList;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumCols(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return insert_entity->num_cols;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Insert_getNumRows(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0;
    }
    return insert_entity->num_rows;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getColSpacing(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0.0;
    }
    return insert_entity->col_spacing;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Insert_getRowSpacing(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL) {
        return 0.0;
    }
    return insert_entity->row_spacing;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Insert_getBlockName(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_INSERT *insert_entity = (Dwg_Entity_INSERT*)(intptr_t)ref;
    if (insert_entity == NULL || insert_entity->block_name == NULL) {
        return NULL;
    }
    const char *chars = insert_entity->block_name;
    char gbk_chars[1024];
    gbk_to_utf8(chars, gbk_chars, sizeof(gbk_chars));
    return (*env)->NewStringUTF(env, strdup(gbk_chars));
}







