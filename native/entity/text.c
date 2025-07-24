#include <jni.h>
#include <stdio.h>
#include "text.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setTextValue(JNIEnv *env, jobject job, jlong ref, jstring value) {
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

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHeight(JNIEnv *env, jobject job, jlong ref, jdouble height) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->height = height;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setRotation(JNIEnv *env, jobject job, jlong ref, jdouble rotation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->rotation = rotation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setInsPt(JNIEnv *env, jobject job, jlong ref, jobject insPt) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, insPt);
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jdouble x = (*env)->GetDoubleField(env, insPt, xField);
    jdouble y = (*env)->GetDoubleField(env, insPt, yField);
    BITCODE_2DPOINT ins_pt = {.x = x, .y = y};
    text_entity->ins_pt = ins_pt;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setAlignmentPt(JNIEnv *env, jobject job, jlong ref, jobject alignmentPt) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    jclass pointCls = (*env)->GetObjectClass(env, alignmentPt);
    jfieldID xField = (*env)->GetFieldID(env, pointCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointCls, "y", "D");
    jdouble x = (*env)->GetDoubleField(env, alignmentPt, xField);
    jdouble y = (*env)->GetDoubleField(env, alignmentPt, yField);
    BITCODE_2DPOINT alignment_pt = {.x = x, .y = y};
    text_entity->alignment_pt = alignment_pt;
    (*env)->DeleteLocalRef(env, pointCls);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setHorizAlignment(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->horiz_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setVertAlignment(JNIEnv *env, jobject job, jlong ref, jint alignment) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->vert_alignment = alignment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setThickness(JNIEnv *env, jobject job, jlong ref, jdouble thickness) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->thickness = thickness;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setElevation(JNIEnv *env, jobject job, jlong ref, jdouble elevation) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->elevation = elevation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setWidthFactor(JNIEnv *env, jobject job, jlong ref, jdouble width_factor) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->width_factor = width_factor;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setObliqueAngle(JNIEnv *env, jobject job, jlong ref, jdouble oblique_angle) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->oblique_angle = oblique_angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setExtrusion(JNIEnv *env, jobject job, jlong ref, jobject extrusion) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    jclass vectorCls = (*env)->GetObjectClass(env, extrusion);
    jfieldID xField = (*env)->GetFieldID(env, vectorCls, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, vectorCls, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, vectorCls, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, extrusion, xField);
    jdouble y = (*env)->GetDoubleField(env, extrusion, yField);
    jdouble z = (*env)->GetDoubleField(env, extrusion, zField);
    Dwg_Bitcode_3BD extrusion2 = {.x = x, .y = y, .z = z};
    text_entity->extrusion = extrusion2;
    (*env)->DeleteLocalRef(env, vectorCls);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_Text_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return (intptr_t)text_entity->parent;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_Text_setStyle(JNIEnv *env, jobject job, jlong ref, jobject style) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    if (style == NULL) {
        return;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (styleClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, styleClass, "ref", "J");
    jlong styleRef = (*env)->GetLongField(env, style, refField);
    Dwg_Object_Ref *style_ref = (Dwg_Object_Ref*)(intptr_t)styleRef;
    text_entity->style = style_ref;
}


JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_Text_getTextValue(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    char *chars = text_entity->text_value;
    if (chars == NULL) {
        return NULL;
    }
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getRotation(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->rotation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getElevation(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->elevation;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getThickness(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->thickness;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getExtrusion(JNIEnv *env, jobject job, jlong ref) {
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
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getHeight(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->height;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getWidthFactor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->width_factor;
}

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getHorizAlignment(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->horiz_alignment;
}

JNIEXPORT jint    JNICALL Java_io_github_maslke_dwg_entity_Text_getVertAlignment(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->vert_alignment;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getInsPt(JNIEnv *env, jobject job, jlong ref) {
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
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_Text_getObliqueAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->oblique_angle;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getAlignmentPt(JNIEnv *env, jobject job, jlong ref) {
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
    (*env)->DeleteLocalRef(env, pointCls);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_Text_getStyle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Entity_TEXT *text_entity = (Dwg_Entity_TEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *style = text_entity->style;
    return createDwgObjectRef(env, style);
}
