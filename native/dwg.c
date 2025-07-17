#include <jni.h>
#include <stdio.h>
#include <dwg.h>
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"
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
    Dwg_Object_BLOCK_HEADER *block_header = dwg_add_BLOCK_HEADER(dwg_data, chars);
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

// end dwg

// parent entity
JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setColorNative(JNIEnv *env, jobject job, jlong ref, jint color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->color.index = color;
    entity->color.flag = 0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLinewtNative(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    entity->linewt = dxf_find_lweight(linewt);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLtypeNative(JNIEnv *env, jobject job, jlong ref, jlong ltype) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *ltype_ref = (Dwg_Object_Ref*)(intptr_t)ltype;
    entity->ltype = ltype_ref;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Parent_setLayerNative(JNIEnv *env, jobject job, jlong ref, jlong layer) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *layer_ref = (Dwg_Object_Ref*)(intptr_t)layer;
    entity->layer = layer_ref;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Parent_getDwgNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    return (jlong)(intptr_t)entity->dwg;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getColorNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    return (jint)entity->color.index;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Parent_getLinewtNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    int type = entity->linewt;
    return find_linewt_by_index(type);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLayerNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *layer = entity->layer;
    return createDwgObjectRef(env, layer);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Parent_getLtypeNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    Dwg_Object_Ref *ltype = entity -> ltype;
    return createDwgObjectRef(env, ltype);
}

// end parent

// dwg object ref
JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getAbsoluteRefNative(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    return (jlong)ref_entity->absolute_ref;
}

JNIEXPORT jshort JNICALL Java_io_github_maslke_dwg_obj_DwgObjectRef_getR11IdxNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Ref *ref_entity = (Dwg_Object_Ref *)(intptr_t)ref;
    return (jshort)ref_entity->r11_idx;
}

// end dwg object ref

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewCtrNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->VIEWCTR.x = x;
    vport->VIEWCTR.y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewSizeNative(JNIEnv *env, jobject job, jlong ref, jdouble viewSize) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->VIEWSIZE = viewSize;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewWidthNative(JNIEnv *env, jobject job, jlong ref, jdouble viewWidth) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->view_width = viewWidth;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setAspectRatioNative(JNIEnv *env, jobject job, jlong ref, jdouble aspectRatio) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->aspect_ratio = aspectRatio;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewTargetNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->view_target.x = x;
    vport->view_target.y = y;
    vport->view_target.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setContrastNative(JNIEnv *env, jobject job, jlong ref, jdouble contrast) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->contrast = contrast;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setBrightnessNative(JNIEnv *env, jobject job, jlong ref, jdouble brightness) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    vport->brightness = brightness;
}

// end object block header
