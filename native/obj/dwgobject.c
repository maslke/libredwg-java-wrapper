#include <jni.h>
#include <stdio.h>
#include "dwgobject.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getTioEntity(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_Entity *entity = object->tio.entity;
    if (entity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObjectEntity";
    return create_object(env, class_name, (jlong)(intptr_t)entity);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getTioObject(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object_Object *obj = object->tio.object;
    if (obj == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObjectObject";
    return create_object(env, class_name, (jlong)(intptr_t)obj);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getHandle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Handle handle = object->handle;
    const char *class_name = "io/github/maslke/dwg/obj/DwgHandle";
    return create_object(env, class_name, (jlong)(intptr_t)(&handle));
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    struct _dwg_struct *parent = object->parent;
    const char *class_name = "io/github/maslke/dwg/Dwg";
    return create_object(env, class_name, (jlong)(intptr_t)parent);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFixedType(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return 0;
    }
    return object->fixedtype;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getSuperType(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return 0;
    }
    return object->supertype;
}