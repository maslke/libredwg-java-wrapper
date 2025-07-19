#include <jni.h>
#include <stdio.h>
#include "image.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClassVersionNative(JNIEnv *env, jobject obj, jlong ref, jlong classVersion) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->class_version = classVersion;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setPt0Native(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->pt0.x = x;
    image_entity->pt0.y = y;
    image_entity->pt0.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setUVecNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->uvec.x = x;
    image_entity->uvec.y = y;
    image_entity->uvec.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setVVecNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->vvec.x = x;
    image_entity->vvec.y = y;
    image_entity->vvec.z = z;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setSizeNative(JNIEnv *env, jobject obj, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    
    image_entity->size.x = x;
    image_entity->size.y = y;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setDisplayPropsNative(JNIEnv *env, jobject obj, jlong ref, jint displayProps) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->display_props = displayProps;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClippingNative(JNIEnv *env, jobject obj, jlong ref, jint clipping) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clipping = clipping;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setBrightnessNative(JNIEnv *env, jobject obj, jlong ref, jint brightness) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->brightness = brightness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setContrastNative(JNIEnv *env, jobject obj, jlong ref, jint contrast) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->contrast = contrast;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setFadeNative(JNIEnv *env, jobject obj, jlong ref, jint fade) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->fade = fade;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipModeNative(JNIEnv *env, jobject obj, jlong ref, jint clipMode) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clip_mode = clipMode;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipBoundaryTypeNative(JNIEnv *env, jobject obj, jlong ref, jint clipBoundaryType) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clip_boundary_type = clipBoundaryType;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setNumClipVertsNative(JNIEnv *env, jobject obj, jlong ref, jlong numClipVerts) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->num_clip_verts = numClipVerts;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipVertsNative(JNIEnv *env, jobject obj, jlong ref, jobject clipVerts) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    jclass listCls = (*env)->FindClass(env, "java/util/List");
    if (listCls == NULL) {
        return;
    }
    jmethodID getMethod = (*env)->GetMethodID(env, listCls, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, listCls, "size", "()I");
    jint size = (*env)->CallIntMethod(env, clipVerts, sizeMethod);
    if (size <= 0) {
        return;
    }
    BITCODE_2RD *clip_verts = malloc(sizeof(BITCODE_2RD) * size);
    if (clip_verts == NULL) {
        return;
    }
    jclass vector2dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vector2dCls == NULL) {
        return;
    }
    jmethodID xMethod = (*env)->GetMethodID(env, vector2dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, vector2dCls, "getY", "()D");
    for (jint i = 0; i < size; i++) {
        jobject vector2dObj = (*env)->CallObjectMethod(env, clipVerts, getMethod, i);
        if (vector2dObj == NULL) {
            jdouble x = (*env)->CallDoubleMethod(env, vector2dObj, xMethod);
            jdouble y = (*env)->CallDoubleMethod(env, vector2dObj, yMethod);
            clip_verts[i].x = x;
            clip_verts[i].y = y;
        }
        else {
            clip_verts[i].x = 0;
            clip_verts[i].y = 0;
        }
    }

    image_entity->clip_verts = clip_verts;
}