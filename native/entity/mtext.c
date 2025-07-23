#include <jni.h>
#include <stdio.h>
#include "text.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setText(JNIEnv *env, jobject job, jlong ref, jstring value) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || value == NULL) {
        return;
    }
    char gbk_text[200];
    const char *chars = (*env)->GetStringUTFChars(env, value, NULL);
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    if (text_entity->text != NULL) {
        free(text_entity->text);
    }
    text_entity->text = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, value, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setInsPt(JNIEnv *env, jobject obj, jlong ref, jobject insPt) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || insPt == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, insPt);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D"); 
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    text_entity->ins_pt.x = (*env)->CallDoubleMethod(env, insPt, getX);
    text_entity->ins_pt.y = (*env)->CallDoubleMethod(env, insPt, getY);
    text_entity->ins_pt.z = (*env)->CallDoubleMethod(env, insPt, getZ);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtrusion(JNIEnv *env, jobject obj, jlong ref, jobject extrusion) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || extrusion == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, extrusion);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    text_entity->extrusion.x = (*env)->CallDoubleMethod(env, extrusion, getX);
    text_entity->extrusion.y = (*env)->CallDoubleMethod(env, extrusion, getY);
    text_entity->extrusion.z = (*env)->CallDoubleMethod(env, extrusion, getZ);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setXAxisDir(JNIEnv *env, jobject obj, jlong ref, jobject xAxisDir) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || xAxisDir == NULL) {
        return;
    }
    jclass cls = (*env)->GetObjectClass(env, xAxisDir);
    jmethodID getX = (*env)->GetMethodID(env, cls, "getX", "()D");
    jmethodID getY = (*env)->GetMethodID(env, cls, "getY", "()D");
    jmethodID getZ = (*env)->GetMethodID(env, cls, "getZ", "()D");

    text_entity->x_axis_dir.x = (*env)->CallDoubleMethod(env, xAxisDir, getX);
    text_entity->x_axis_dir.y = (*env)->CallDoubleMethod(env, xAxisDir, getY);
    text_entity->x_axis_dir.z = (*env)->CallDoubleMethod(env, xAxisDir, getZ);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setStyle(JNIEnv *env, jobject obj, jlong ref, jobject style) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || style == NULL) {
        return;
    }
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/DwgObjectRef");
    jmethodID getRef = (*env)->GetMethodID(env, refClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, style, getRef);
    if (reference == 0) {
        return;
    }
    text_entity->style = (Dwg_Object_Ref*)reference;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setTextHeight(JNIEnv *env, jobject obj, jlong ref, jdouble textHeight) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->text_height = textHeight;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setRectWidth(JNIEnv *env, jobject obj, jlong ref, jdouble rectWidth) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->rect_width = rectWidth;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setRectHeight(JNIEnv *env, jobject obj, jlong ref, jdouble rectHeight) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->rect_height = rectHeight;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAttachment(JNIEnv *env, jobject obj, jlong ref, jint attachment) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->attachment = attachment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setFlowDir(JNIEnv *env, jobject obj, jlong ref, jint flowDir) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->flow_dir = flowDir;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtentsWidth(JNIEnv *env, jobject obj, jlong ref, jdouble extentWidth) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->extents_width = extentWidth;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setExtentsHeight(JNIEnv *env, jobject obj, jlong ref, jdouble extentHeight) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->extents_height = extentHeight;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setLinespaceStyle(JNIEnv *env, jobject obj, jlong ref, jint linespaceStyle) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->linespace_style = linespaceStyle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setLinespaceFactor(JNIEnv *env, jobject obj, jlong ref, jdouble linespaceFactor) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->linespace_factor = linespaceFactor;
}


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setUnknownB0(JNIEnv *env, jobject obj, jlong ref, jint unknownB0) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->unknown_b0 = unknownB0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillFlag(JNIEnv *env, jobject obj, jlong ref, jint bgFillFlag) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->bg_fill_flag = bgFillFlag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillScale(JNIEnv *env, jobject obj, jlong ref, jint bgFillScale) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->bg_fill_scale = bgFillScale;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillTrans(JNIEnv *env, jobject obj, jlong ref, jint bgFillTrans) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->bg_fill_trans = bgFillTrans;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setIsNotAnnotative(JNIEnv *env, jobject obj, jlong ref, jint isNotAnnotative) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->is_not_annotative = isNotAnnotative;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setClassVersion(JNIEnv *env, jobject obj, jlong ref, jint classVersion) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->class_version = classVersion;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setDefaultFlag(JNIEnv *env, jobject obj, jlong ref, jint defaultFlag) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->default_flag = defaultFlag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAppid(JNIEnv *env, jobject obj, jlong ref, jobject appid) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || appid == NULL) {
        return;
    }
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/DwgObjectRef");
    jmethodID getRef = (*env)->GetMethodID(env, refClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, appid, getRef);
    if (reference == 0) {
        return;
    }
    if (text_entity->appid != NULL) {
        free(text_entity->appid);
    }
    text_entity->appid = (Dwg_Object_Ref*)reference;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setIgnoreAttachment(JNIEnv *env, jobject obj, jlong ref, jlong ignoreAttachment) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->ignore_attachment = ignoreAttachment;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnType(JNIEnv *env, jobject obj, jlong ref, jint columnType) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->column_type = columnType;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setNumFragments(JNIEnv *env, jobject obj, jlong ref, jlong numFragments) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->numfragments = numFragments;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnWidth(JNIEnv *env, jobject obj, jlong ref, jdouble columnWidth) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->column_width = columnWidth;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setGutter(JNIEnv *env, jobject obj, jlong ref, jdouble gutter) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->gutter = gutter;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setAutoHeight(JNIEnv *env, jobject obj, jlong ref, jint autoHeight) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->auto_height = autoHeight;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setFlowReversed(JNIEnv *env, jobject obj, jlong ref, jint flowReversed) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->flow_reversed = flowReversed;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setNumColumnHeights(JNIEnv *env, jobject obj, jlong ref, jlong numColumnHeights) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    text_entity->num_column_heights = numColumnHeights;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setColumnHeights(JNIEnv *env, jobject obj, jlong ref, jobject columnHeights) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || columnHeights == NULL) {
        return;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID get = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID size = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint length = (*env)->CallIntMethod(env, columnHeights, size);
    text_entity->column_heights = (double*)malloc(length * sizeof(double));
    for (jint i = 0; i < length; i++) {
        jobject item = (*env)->CallObjectMethod(env, columnHeights, get, i);
        jclass cls = (*env)->GetObjectClass(env, item);
        jmethodID getDouble = (*env)->GetMethodID(env, cls, "doubleValue", "()D");
        text_entity->column_heights[i] = (*env)->CallDoubleMethod(env, item, getDouble);
    }
    (*env)->DeleteLocalRef(env, listClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getInsPt(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Point3d");
    jmethodID init = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    jobject point = (*env)->NewObject(env, pointClass, init, text_entity->ins_pt.x, text_entity->ins_pt.y, text_entity->ins_pt.z);
    (*env)->DeleteLocalRef(env, pointClass);
    return point;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getExtrusion(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass vectorClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Vector3d");
    jmethodID init = (*env)->GetMethodID(env, vectorClass, "<init>", "(DDD)V");
    jobject vector = (*env)->NewObject(env, vectorClass, init, text_entity->extrusion.x, text_entity->extrusion.y, text_entity->extrusion.z);
    (*env)->DeleteLocalRef(env, vectorClass);
    return vector;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getXAxisDir(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Point3d");
    jmethodID init = (*env)->GetMethodID(env, pointClass, "<init>", "(DDD)V");
    jobject point = (*env)->NewObject(env, pointClass, init, text_entity->x_axis_dir.x, text_entity->x_axis_dir.y, text_entity->x_axis_dir.z);
    (*env)->DeleteLocalRef(env, pointClass);
    return point;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getRectHeight(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->rect_height;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getRectWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->rect_width;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getTextHeight(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->text_height;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getAttachment(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->attachment;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getFlowDir(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->flow_dir;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getExtentsWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->extents_width;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getExtentsHeight(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->extents_height;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_entity_MText_getText(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || text_entity->text == NULL) {
        return NULL;
    }
    
    char *chars = text_entity->text;
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getStyle(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL || text_entity->text == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *style = text_entity->style;
    return createDwgObjectRef(env, style);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getLinespaceStyle(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->linespace_style;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getLinespaceFactor(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->linespace_factor;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getUnknownB0(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->unknown_b0;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->bg_fill_flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillScale(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->bg_fill_scale;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillTrans(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->bg_fill_trans;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getBgFillColor(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    return createDwgColor(env, (Dwg_Color*)&text_entity->bg_fill_color);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setBgFillColor(JNIEnv *env, jobject obj, jlong ref, jobject bgFillColor) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgColor");
    if (refClass == NULL) {
        return;
    }
    jmethodID getRef = (*env)->GetMethodID(env, refClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, bgFillColor, getRef);
    if (reference == 0) {
        return;
    }
    Dwg_Color *color = (Dwg_Color*)(intptr_t)reference;
    text_entity->bg_fill_color = *color;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getIsNotAnnotative(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->is_not_annotative;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getClassVersion(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->class_version;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getDefaultFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->default_flag;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getAppid(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *appid = text_entity->appid;
    return createDwgObjectRef(env, appid);
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getIgnoreAttachment(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->ignore_attachment;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnType(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->column_type;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getNumFragments(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->numfragments;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnWidth(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->column_width;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_entity_MText_getGutter(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->gutter;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getAutoHeight(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->auto_height;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_entity_MText_getFlowReversed(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->flow_reversed;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getNumColumnHeights(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return text_entity->num_column_heights;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_entity_MText_getColumnHeights(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return NULL;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID init = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject list = (*env)->NewObject(env, listClass, init);
    jmethodID add = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
    jmethodID doubleInit = (*env)->GetMethodID(env, doubleClass, "<init>", "(D)V");

    for (int i = 0; i < text_entity->num_column_heights; i++) {
        jobject doubleObj = (*env)->NewObject(env, doubleClass, doubleInit, text_entity->column_heights[i]);
        (*env)->CallBooleanMethod(env, list, add, doubleObj);
    }
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, doubleClass);
    return list;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_MText_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)text_entity->parent;
}
