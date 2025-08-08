#include <jni.h>
#include <stdio.h>
#include "dwgobject.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "dwg.h"
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

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedEntity(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *entity = get_first_owned_entity(object);
    if (entity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)entity);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedEntity(JNIEnv *env, jobject job, jlong ref, jobject current) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;    
    if (object == NULL) {
        return NULL;
    }
    jclass objClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObject"); 
    if (objClass == NULL) {
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, objClass, "ref", "J");
    jlong refValue = (*env)->GetLongField(env, current, refField);
    Dwg_Object *current_obj = (Dwg_Object*)(intptr_t)refValue;
    Dwg_Object *entity = get_next_owned_entity(object, current_obj);
    if (entity == NULL) {
        (*env)->DeleteLocalRef(env, objClass);
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    jobject obj = create_object(env, class_name, (jlong)(intptr_t)entity);
    (*env)->DeleteLocalRef(env, objClass);
    return obj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedBlock(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *block = get_first_owned_block(object);
    if (block == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)block);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedBlock(JNIEnv *env, jobject job, jlong ref, jobject current) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL || current == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    jlong refValue = get_object_ref(env, class_name, current);
    if (refValue == 0) {
        return NULL;
    }
    Dwg_Object *current_obj = (Dwg_Object*)(intptr_t)refValue;
    Dwg_Object *block = get_next_owned_block(object, current_obj);
    if (block == NULL) {
        return NULL;
    }
    return create_object(env, class_name, (jlong)(intptr_t)block);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getLastOwnedBlock(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *block = get_last_owned_block(object);
    if (block == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)block);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getFirstOwnedSubEntity(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *subentity = get_first_owned_subentity(object);
    if (subentity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)subentity);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextOwnedSubEntity(JNIEnv *env, jobject job, jlong ref, jobject current) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL || current == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    jlong refValue = get_object_ref(env, class_name, current);
    if (refValue == 0) {
        return NULL;
    }
    Dwg_Object *current_obj = (Dwg_Object*)(intptr_t)refValue;
    Dwg_Object *subentity = get_next_owned_subentity(object, current_obj);
    if (subentity == NULL) {
        return NULL;
    }
    return create_object(env, class_name, (jlong)(intptr_t)subentity);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextObject(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *next_object = dwg_next_object(object);
    if (next_object == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)next_object);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObject_getNextEntity(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object *object = (Dwg_Object*)(intptr_t)ref;
    if (object == NULL) {
        return NULL;
    }
    Dwg_Object *next_entity = dwg_next_entity(object);
    if (next_entity == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObject";
    return create_object(env, class_name, (jlong)(intptr_t)next_entity);
}