#include <jni.h>
#include <stdio.h>
#include "image.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClassVersion(JNIEnv *env, jobject obj, jlong ref, jlong classVersion) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->class_version = classVersion;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setPt0(JNIEnv *env, jobject obj, jlong ref, jobject pt0) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || pt0 == NULL) {
        return;
    }
    
    jclass point3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (point3dCls == NULL) {
        return;
    }
    
    jmethodID xMethod = (*env)->GetMethodID(env, point3dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, point3dCls, "getY", "()D");
    jmethodID zMethod = (*env)->GetMethodID(env, point3dCls, "getZ", "()D");
    
    if (xMethod && yMethod && zMethod) {
        image_entity->pt0.x = (*env)->CallDoubleMethod(env, pt0, xMethod);
        image_entity->pt0.y = (*env)->CallDoubleMethod(env, pt0, yMethod);
        image_entity->pt0.z = (*env)->CallDoubleMethod(env, pt0, zMethod);
    }
    (*env)->DeleteLocalRef(env, point3dCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setUVec(JNIEnv *env, jobject obj, jlong ref, jobject uVec) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || uVec == NULL) {
        return;
    }
    
    jclass vector3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vector3dCls == NULL) {
        return;
    }
    
    jmethodID xMethod = (*env)->GetMethodID(env, vector3dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, vector3dCls, "getY", "()D");
    jmethodID zMethod = (*env)->GetMethodID(env, vector3dCls, "getZ", "()D");
    
    if (xMethod && yMethod && zMethod) {
        image_entity->uvec.x = (*env)->CallDoubleMethod(env, uVec, xMethod);
        image_entity->uvec.y = (*env)->CallDoubleMethod(env, uVec, yMethod);
        image_entity->uvec.z = (*env)->CallDoubleMethod(env, uVec, zMethod);
    }
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setVVec(JNIEnv *env, jobject obj, jlong ref, jobject vVec) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || vVec == NULL) {
        return;
    }
    
    jclass vector3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vector3dCls == NULL) {
        return;
    }
    
    jmethodID xMethod = (*env)->GetMethodID(env, vector3dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, vector3dCls, "getY", "()D");
    jmethodID zMethod = (*env)->GetMethodID(env, vector3dCls, "getZ", "()D");
    
    if (xMethod && yMethod && zMethod) {
        image_entity->vvec.x = (*env)->CallDoubleMethod(env, vVec, xMethod);
        image_entity->vvec.y = (*env)->CallDoubleMethod(env, vVec, yMethod);
        image_entity->vvec.z = (*env)->CallDoubleMethod(env, vVec, zMethod);
    }
    (*env)->DeleteLocalRef(env, vector3dCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setSize(JNIEnv *env, jobject obj, jlong ref, jobject size) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || size == NULL) {
        return;
    }
    
    jclass vector2dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vector2dCls == NULL) {
        return;
    }
    
    jmethodID xMethod = (*env)->GetMethodID(env, vector2dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, vector2dCls, "getY", "()D");
    
    if (xMethod && yMethod) {
        image_entity->size.x = (*env)->CallDoubleMethod(env, size, xMethod);
        image_entity->size.y = (*env)->CallDoubleMethod(env, size, yMethod);
    }
    (*env)->DeleteLocalRef(env, vector2dCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setDisplayProps(JNIEnv *env, jobject obj, jlong ref, jint displayProps) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->display_props = displayProps;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipping(JNIEnv *env, jobject obj, jlong ref, jint clipping) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clipping = clipping;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setBrightness(JNIEnv *env, jobject obj, jlong ref, jint brightness) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->brightness = brightness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setContrast(JNIEnv *env, jobject obj, jlong ref, jint contrast) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->contrast = contrast;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setFade(JNIEnv *env, jobject obj, jlong ref, jint fade) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->fade = fade;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipMode(JNIEnv *env, jobject obj, jlong ref, jint clipMode) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clip_mode = clipMode;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipBoundaryType(JNIEnv *env, jobject obj, jlong ref, jint clipBoundaryType) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->clip_boundary_type = clipBoundaryType;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setNumClipVerts(JNIEnv *env, jobject obj, jlong ref, jlong numClipVerts) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return;
    }
    image_entity->num_clip_verts = numClipVerts;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setClipVerts(JNIEnv *env, jobject obj, jlong ref, jobject clipVerts) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || clipVerts == NULL) {
        return;
    }
    
    jclass listCls = (*env)->FindClass(env, "java/util/ArrayList");
    if (listCls == NULL) {
        return;
    }
    
    jmethodID getMethod = (*env)->GetMethodID(env, listCls, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, listCls, "size", "()I");
    
    if (getMethod == NULL || sizeMethod == NULL) {
        (*env)->DeleteLocalRef(env, listCls);
        return;
    }
    
    jint size = (*env)->CallIntMethod(env, clipVerts, sizeMethod);
    if (size <= 0) {
        (*env)->DeleteLocalRef(env, listCls);
        return;
    }
    
    BITCODE_2RD *clip_verts = malloc(sizeof(BITCODE_2RD) * size);
    if (clip_verts == NULL) {
        (*env)->DeleteLocalRef(env, listCls);
        return;
    }
    
    jclass vector2dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vector2dCls == NULL) {
        free(clip_verts);
        (*env)->DeleteLocalRef(env, listCls);
        return;
    }
    
    jmethodID xMethod = (*env)->GetMethodID(env, vector2dCls, "getX", "()D");
    jmethodID yMethod = (*env)->GetMethodID(env, vector2dCls, "getY", "()D");
    
    if (xMethod == NULL || yMethod == NULL) {
        free(clip_verts);
        (*env)->DeleteLocalRef(env, listCls);
        (*env)->DeleteLocalRef(env, vector2dCls);
        return;
    }
    
    for (jint i = 0; i < size; i++) {
        jobject vector2dObj = (*env)->CallObjectMethod(env, clipVerts, getMethod, i);
        if (vector2dObj != NULL) {
            jdouble x = (*env)->CallDoubleMethod(env, vector2dObj, xMethod);
            jdouble y = (*env)->CallDoubleMethod(env, vector2dObj, yMethod);
            clip_verts[i].x = x;
            clip_verts[i].y = y;
            (*env)->DeleteLocalRef(env, vector2dObj);
        } else {
            clip_verts[i].x = 0;
            clip_verts[i].y = 0;
        }
    }
    
    if (image_entity->clip_verts) {
        free(image_entity->clip_verts);
    }
    image_entity->clip_verts = clip_verts;
    (*env)->DeleteLocalRef(env, listCls);
    (*env)->DeleteLocalRef(env, vector2dCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setImageDef(JNIEnv *env, jobject obj, jlong ref, jobject imageDef) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || imageDef == NULL) {
        return;
    }
    
    jclass refCls = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refCls == NULL) {
        return;
    }
    
    jmethodID getRefMethod = (*env)->GetMethodID(env, refCls, "getRef", "()J");
    if (getRefMethod != NULL) {
        jlong refValue = (*env)->CallLongMethod(env, imageDef, getRefMethod);
        image_entity->imagedef = (Dwg_Object_Ref*)(intptr_t)refValue;
    }
    (*env)->DeleteLocalRef(env, refCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Image_setImageDefReactor(JNIEnv *env, jobject obj, jlong ref, jobject imageDefReactor) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || imageDefReactor == NULL) {
        return;
    }
    
    jclass refCls = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refCls == NULL) {
        return;
    }
    
    jmethodID getRefMethod = (*env)->GetMethodID(env, refCls, "getRef", "()J");
    if (getRefMethod != NULL) {
        jlong refValue = (*env)->CallLongMethod(env, imageDefReactor, getRefMethod);
        image_entity->imagedefreactor = (Dwg_Object_Ref*)(intptr_t)refValue;
    }
    (*env)->DeleteLocalRef(env, refCls);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)(image_entity->parent);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getClassVersion(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->class_version;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getPt0(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return NULL;
    }
    
    jclass point3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (point3dCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, point3dCls, "<init>", "(DDD)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, point3dCls);
        return NULL;
    }
    
    jobject pt0 = (*env)->NewObject(env, point3dCls, constructor,
                            image_entity->pt0.x,
                            image_entity->pt0.y,
                            image_entity->pt0.z);
    (*env)->DeleteLocalRef(env, point3dCls);
    return pt0;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getUVec(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return NULL;
    }
    
    jclass vector3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vector3dCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, vector3dCls, "<init>", "(DDD)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, vector3dCls);
        return NULL;
    }
    
    jobject uvec = (*env)->NewObject(env, vector3dCls, constructor,
                            image_entity->uvec.x,
                            image_entity->uvec.y,
                            image_entity->uvec.z);
    (*env)->DeleteLocalRef(env, vector3dCls);
    return uvec;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getVVec(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return NULL;
    }
    
    jclass vector3dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (vector3dCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, vector3dCls, "<init>", "(DDD)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, vector3dCls);
        return NULL;
    }
    
    jobject vvec = (*env)->NewObject(env, vector3dCls, constructor,
                            image_entity->vvec.x,
                            image_entity->vvec.y,
                            image_entity->vvec.z);
    (*env)->DeleteLocalRef(env, vector3dCls);
    return vvec;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getSize(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return NULL;
    }
    
    jclass vector2dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vector2dCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, vector2dCls, "<init>", "(DD)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, vector2dCls);
        return NULL;
    }
    
    jobject size = (*env)->NewObject(env, vector2dCls, constructor,
                            image_entity->size.x,
                            image_entity->size.y);
    (*env)->DeleteLocalRef(env, vector2dCls);
    return size;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getDisplayProps(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->display_props;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipping(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->clipping;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getBrightness(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->brightness;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getContrast(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->contrast;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getFade(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->fade;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipMode(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->clip_mode;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_Image_getClipBoundaryType(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->clip_boundary_type;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Image_getNumClipVerts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL) {
        return 0;
    }
    return image_entity->num_clip_verts;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getClipVerts(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || image_entity->clip_verts == NULL) {
        return NULL;
    }
    
    jclass arrayListCls = (*env)->FindClass(env, "java/util/ArrayList");
    if (arrayListCls == NULL) {
        return NULL;
    }
    
    jmethodID arrayListConstructor = (*env)->GetMethodID(env, arrayListCls, "<init>", "()V");
    jmethodID addMethod = (*env)->GetMethodID(env, arrayListCls, "add", "(Ljava/lang/Object;)Z");
    
    if (arrayListConstructor == NULL || addMethod == NULL) {
        (*env)->DeleteLocalRef(env, arrayListCls);
        return NULL;
    }
    
    jobject arrayList = (*env)->NewObject(env, arrayListCls, arrayListConstructor);
    if (arrayList == NULL) {
        (*env)->DeleteLocalRef(env, arrayListCls);
        return NULL;
    }
    
    jclass vector2dCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vector2dCls == NULL) {
        (*env)->DeleteLocalRef(env, arrayListCls);
        return NULL;
    }
    
    jmethodID vector2dConstructor = (*env)->GetMethodID(env, vector2dCls, "<init>", "(DD)V");
    if (vector2dConstructor == NULL) {
        (*env)->DeleteLocalRef(env, arrayListCls);
        (*env)->DeleteLocalRef(env, vector2dCls);
        return NULL;
    }
    
    for (long i = 0; i < image_entity->num_clip_verts; i++) {
        jobject vector2d = (*env)->NewObject(env, vector2dCls, vector2dConstructor,
                                            image_entity->clip_verts[i].x,
                                            image_entity->clip_verts[i].y);
        if (vector2d != NULL) {
            (*env)->CallBooleanMethod(env, arrayList, addMethod, vector2d);
            (*env)->DeleteLocalRef(env, vector2d);
        }
    }
    
    (*env)->DeleteLocalRef(env, arrayListCls);
    (*env)->DeleteLocalRef(env, vector2dCls);
    return arrayList;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getImageDef(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || image_entity->imagedef == NULL) {
        return NULL;
    }
    
    jclass refCls = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, refCls, "<init>", "()V");
    jmethodID setRefMethod = (*env)->GetMethodID(env, refCls, "setRef", "(J)V");
    
    if (constructor == NULL || setRefMethod == NULL) {
        return NULL;
    }
    
    jobject refObj = (*env)->NewObject(env, refCls, constructor);
    if (refObj != NULL) {
        (*env)->CallVoidMethod(env, refObj, setRefMethod, (jlong)(intptr_t)image_entity->imagedef);
    }
    (*env)->DeleteLocalRef(env, refCls);
    return refObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Image_getImageDefReactor(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_IMAGE *image_entity = (Dwg_Entity_IMAGE*)(intptr_t)ref;
    if (image_entity == NULL || image_entity->imagedefreactor == NULL) {
        return NULL;
    }
    
    jclass refCls = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refCls == NULL) {
        return NULL;
    }
    
    jmethodID constructor = (*env)->GetMethodID(env, refCls, "<init>", "()V");
    jmethodID setRefMethod = (*env)->GetMethodID(env, refCls, "setRef", "(J)V");
    
    if (constructor == NULL || setRefMethod == NULL) {
        (*env)->DeleteLocalRef(env, refCls);
        return NULL;
    }
    
    jobject refObj = (*env)->NewObject(env, refCls, constructor);
    if (refObj != NULL) {
        (*env)->CallVoidMethod(env, refObj, setRefMethod, (jlong)(intptr_t)image_entity->imagedefreactor);
    }
    
    (*env)->DeleteLocalRef(env, refCls);
    return refObj;
}