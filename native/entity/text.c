#include <jni.h>
#include <stdio.h>
#include "text.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setTextValueNative(JNIEnv *env, jobject job, jlong ref, jstring value) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    char gbk_text[200];
    const char *chars = (*env)->GetStringUTFChars(env, value, NULL);
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    text_entity->text_value = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, value, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHeightNative(JNIEnv *env, jobject job, jlong ref, jdouble height) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->height = height;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setRotationNative(JNIEnv *env, jobject job, jlong ref, jdouble rotation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setInsPtNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    BITCODE_2DPOINT ins_pt = {.x = x, .y = y};
    text_entity->ins_pt = ins_pt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setAlignmentPtNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    BITCODE_2DPOINT alignment_pt = {.x = x, .y = y};
    text_entity->alignment_pt = alignment_pt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHorizAlignmentNative(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->horiz_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setVertAlignmentNative(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->vert_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setThicknessNative(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setElevationNative(JNIEnv *env, jobject job, jlong ref, jdouble elevation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->elevation = elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setWidthFactorNative(JNIEnv *env, jobject job, jlong ref, jdouble width_factor) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->width_factor = width_factor;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setObliqueAngleNative(JNIEnv *env, jobject job, jlong ref, jdouble oblique_angle) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->oblique_angle = oblique_angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setExtrusionNative(JNIEnv *env, jobject job, jlong ref, jdouble x, jdouble y, jdouble z) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    Dwg_Bitcode_3BD extrusion = {.x = x, .y = y, .z = z};
    text_entity->extrusion = extrusion;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Text_getParentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return (intptr_t)text_entity->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setStyleNative(JNIEnv *env, jobject job, jlong ref, jlong style) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    Dwg_Object_Ref *style_ref = (Dwg_Object_Ref*)(intptr_t)style;
    text_entity->style = style_ref;
}


JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Text_getTextValueNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    char *chars = text_entity->text_value;
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getRotationNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->rotation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getElevationNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->elevation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getThicknessNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getExtrusionNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Vector3d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointCls, "z", "D");
    (*env)->SetDoubleField(env, pointObj, xField, text_entity->extrusion.x);
    (*env)->SetDoubleField(env, pointObj, yField, text_entity->extrusion.y);
    (*env)->SetDoubleField(env, pointObj, zField, text_entity->extrusion.z);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getHeightNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->height;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getWidthFactorNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->width_factor;
}

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getHorizAlignmentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->horiz_alignment;
}

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getVertAlignmentNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->vert_alignment;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getInsPtNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    (*env)->SetDoubleField(env, pointObj, xField, text_entity->ins_pt.x);
    (*env)->SetDoubleField(env, pointObj, yField, text_entity->ins_pt.y);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getObliqueAngleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->oblique_angle;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getAlignmentPtNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass pointCls = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    if (pointCls == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointCls, "<init>", "()V");
    jobject pointObj = (*env)->NewObject(env, pointCls, constructor);

    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    (*env)->SetDoubleField(env, pointObj, xField, text_entity->alignment_pt.x);
    (*env)->SetDoubleField(env, pointObj, yField, text_entity->alignment_pt.y);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getStyleNative(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *style = text_entity->style;
    return createDwgObjectRef(env, style);
}
