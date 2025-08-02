#include <jni.h>
#include "vport.h"
#include <dwg_api.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewCtr(JNIEnv *env, jobject job, jlong ref, jobject viewCtr) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    if (viewCtr == NULL) {
        return;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jdouble x = (*env)->GetDoubleField(env, viewCtr, xField);
    jdouble y = (*env)->GetDoubleField(env, viewCtr, yField);
    vport->VIEWCTR.x = x;
    vport->VIEWCTR.y = y;
    (*env)->DeleteLocalRef(env, vectorClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewCtr(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector2d");
    if (vectorClass == NULL) {
        return NULL;
    }
    jmethodID vectorConstructor = (*env)->GetMethodID(env, vectorClass, "<init>", "(DD)V");
    if (vectorConstructor == NULL) {
        (*env)->DeleteLocalRef(env, vectorClass);
        return NULL;
    }
    jfieldID xField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jdouble x = vport->VIEWCTR.x;
    jdouble y = vport->VIEWCTR.y;
    jobject vector = (*env)->NewObject(env, vectorClass, vectorConstructor, x, y);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewSize(JNIEnv *env, jobject job, jlong ref, jdouble viewSize) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    vport->VIEWSIZE = viewSize;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewSize(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return 0;
    }
    return vport->VIEWSIZE;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewWidth(JNIEnv *env, jobject job, jlong ref, jdouble viewWidth) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    vport->view_width = viewWidth;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewWidth(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return 0;
    }
    return vport->view_width;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setAspectRatio(JNIEnv *env, jobject job, jlong ref, jdouble aspectRatio) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    vport->aspect_ratio = aspectRatio;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getAspectRatio(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return 0;
    }
    return vport->aspect_ratio;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setViewTarget(JNIEnv *env, jobject job, jlong ref, jobject viewTarget) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    if (viewTarget == NULL) {
        return;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, viewTarget, xField);
    jdouble y = (*env)->GetDoubleField(env, viewTarget, yField);
    jdouble z = (*env)->GetDoubleField(env, viewTarget, zField);
    vport->view_target.x = x;
    vport->view_target.y = y;
    vport->view_target.z = z;
    (*env)->DeleteLocalRef(env, pointClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getViewTarget(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID pointConstructor = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    if (pointConstructor == NULL) {
        (*env)->DeleteLocalRef(env, pointClass);
        return NULL;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    jdouble x = vport->view_target.x;
    jdouble y = vport->view_target.y;
    jdouble z = vport->view_target.z;
    jobject point = (*env)->NewObject(env, pointClass, pointConstructor, x, y, z);
    (*env)->DeleteLocalRef(env, pointClass);
    return point;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setContrast(JNIEnv *env, jobject job, jlong ref, jdouble contrast) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    vport->contrast = contrast;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getContrast(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return 0;
    }
    return vport->contrast;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_setBrightness(JNIEnv *env, jobject job, jlong ref, jdouble brightness) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return;
    }
    vport->brightness = brightness;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectVport_getBrightness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_VPORT *vport = (Dwg_Object_VPORT *)(intptr_t)ref;
    if (vport == NULL) {
        return 0;
    }
    return vport->brightness;
}
