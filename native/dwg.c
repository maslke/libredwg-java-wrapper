#include <jni.h>
#include <stdio.h>
#include <dwg.h>
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersionNative(JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "0.13.3");
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_createNative(JNIEnv *env, jclass clazz) {
    Dwg_Data *dwg_data = dwg_new_Document (R_2000, 0, 0);
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_Dwg_saveNative(JNIEnv *env, jobject obj, jlong ref, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    dwg_data->header.version = R_2000;
    const char *file = (*env)->GetStringUTFChars(env, filename, NULL);
    jint ret = dwg_write_file(file, dwg_data);
    (*env)->ReleaseStringUTFChars(env, filename, file);
    dwg_free(dwg_data);
    return ret;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getObjectBlockHeaderNative(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    int error = 0;
    Dwg_Object_BLOCK_HEADER *hdr = dwg_get_block_header(dwg_data, &error);
    if (hdr == NULL) {
      Dwg_Object *mspace = dwg_model_space_object (dwg_data);
      if (mspace != NULL) {
        hdr = mspace->tio.object->tio.BLOCK_HEADER;
      }
    }
    return (jlong)(intptr_t)hdr;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_createObjectBlockHeaderNative(JNIEnv *env, jobject job, jlong ref, jstring name) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Object_BLOCK_HEADER *block_header = dwg_add_BLOCK_HEADER(dwg_data, strdup(gbk_text));
    (*env)->ReleaseStringUTFChars(env, name, chars);
    return (jlong)(intptr_t)block_header;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_openNative(JNIEnv *env, jclass clazz, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data *) malloc(sizeof(Dwg_Data));
    const char *file = (*env)->GetStringUTFChars(env, filename, NULL);
    memset(dwg_data, 0, sizeof(Dwg_Data));
    dwg_read_file(file, dwg_data);
    (*env)->ReleaseStringUTFChars(env, filename, file);
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_Dwg_setCodePageNative(JNIEnv *env, jobject job, jlong ref, jstring code_page) {
    Dwg_Data *dwg_data = (Dwg_Data *)(intptr_t)ref;
    const char *code = (*env)->GetStringUTFChars(env, code_page, NULL);
    dwg_data->header_vars.DWGCODEPAGE = strdup(code);
    (*env)->ReleaseStringUTFChars(env, code_page, code);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_findTableHandleNative(JNIEnv *env, jobject job, jlong ref, jstring name, jstring table) {
    Dwg_Data *dwg_data = (Dwg_Data *)(intptr_t)ref;
    const char *name_str = (*env)->GetStringUTFChars(env, name, NULL);
    const char *table_str = (*env)->GetStringUTFChars(env, table, NULL);
    Dwg_Object_Ref *table_entity = dwg_find_tablehandle(dwg_data, name_str, table_str);
    (*env)->ReleaseStringUTFChars(env, name, name_str);
    (*env)->ReleaseStringUTFChars(env, table, table_str);
    return (jlong)(intptr_t)table_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_addHandleRefNative(JNIEnv *env, jobject job, jlong ref, jint code, jlong value, jlong obj) {
    Dwg_Data *dwg_data = (Dwg_Data *)(intptr_t)ref;
    Dwg_Object *obj_entity = NULL;
    if (obj != 0) {
        obj_entity = (Dwg_Object *)(intptr_t)obj;
    }
    Dwg_Object_Ref *ref_entity = dwg_add_handleref(dwg_data, code, value, obj_entity);
    return (jlong)(intptr_t)ref_entity;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getVportNative(JNIEnv *env, jobject job, jlong ref, jstring name) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    Dwg_Object_VPORT **vports = dwg_getall_VPORT(dwg_data);
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Object_VPORT *vp= NULL;
    for (int i = 0; vports[i] != NULL; i++) {
        Dwg_Object_VPORT *vport = vports[i];
        if (strcmp(vport->name, gbk_text) == 0) {
            vp = vport;
            break;
        }
    }
    if (vports != NULL) {
        free(vports);
    }
    (*env)->ReleaseStringUTFChars(env, name, chars);
    if (vp == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)vp;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_Dwg_releaseNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    if (dwg_data != NULL) {
        dwg_free(dwg_data);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getNumObjects(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    if (dwg_data == NULL) {
        return 0;
    }
    return (jlong)dwg_data->num_objects;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_getNumEntities(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    if (dwg_data == NULL) {
        return 0;
    }
    return (jlong)dwg_data->num_entities;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_Dwg_getObject(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Data *dwg_data = (Dwg_Data*)(intptr_t)ref;
    if (dwg_data == NULL) {
        return NULL;
    }
    
    int num_objects = dwg_data->num_objects;
    jclass listclass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listclass == NULL) {
        return NULL;
    }
    jmethodID list_init = (*env)->GetMethodID(env, listclass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listclass, list_init);
    jmethodID list_add = (*env)->GetMethodID(env, listclass, "add", "(Ljava/lang/Object;)Z");

    jclass objectclass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObject");
    if (objectclass == NULL) {
        (*env)->DeleteLocalRef(env, list);
        return NULL;
    }
    jmethodID object_init = (*env)->GetMethodID(env, objectclass, "<init>", "(J)V");
    for (int i = 0; i < num_objects; i++) {
        Dwg_Object *obj = &dwg_data->object[i];
        jobject object = (*env)->NewObject(env, objectclass, object_init, (jlong)(intptr_t)obj);
        (*env)->CallBooleanMethod(env, list, list_add, object);
    }
    (*env)->DeleteLocalRef(env, listclass);
    (*env)->DeleteLocalRef(env, objectclass);
    return list;
}
