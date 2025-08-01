#include <jni.h>
#include <stdio.h>
#include "objectstyle.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setIsShape(JNIEnv *env, jobject job, jlong ref, jint isShape) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->is_shape = isShape;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getIsShape(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->is_shape;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setIsVertical(JNIEnv *env, jobject job, jlong ref, jint isVertical) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->is_vertical = isVertical;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getIsVertical(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->is_vertical;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setTextSize(JNIEnv *env, jobject job, jlong ref, jdouble textSize) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->text_size = textSize;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getTextSize(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->text_size;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setWidthFactor(JNIEnv *env, jobject job, jlong ref, jdouble widthFactor) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->width_factor = widthFactor;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getWidthFactor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->width_factor;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setObliqueAngle(JNIEnv *env, jobject job, jlong ref, jdouble obliqueAngle) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->oblique_angle = obliqueAngle;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getObliqueAngle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->oblique_angle;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setGeneration(JNIEnv *env, jobject job, jlong ref, jint generation) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->generation = generation;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getGeneration(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->generation;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setLastHeight(JNIEnv *env, jobject job, jlong ref, jdouble lastHeight) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    style->last_height = lastHeight;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getLastHeight(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return 0;
    }
    return style->last_height;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setFontFile(JNIEnv *env, jobject job, jlong ref, jstring fontFile) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    const char *fontFileStr = (*env)->GetStringUTFChars(env, fontFile, NULL);
    if (fontFileStr == NULL) {
        return;
    }
    char gbk_text[200];
    utf8_to_gbk(fontFileStr, gbk_text, sizeof(gbk_text));
    (*env)->ReleaseStringUTFChars(env, fontFile, fontFileStr);
    style->font_file = (BITCODE_TV) gbk_text;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getFontFile(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return NULL;
    }
    char *c_text = (char *) style->font_file;
    if (c_text == NULL) {
        return NULL;
    }
    char utf_text[200];
    gbk_to_utf8(c_text, utf_text, sizeof(utf_text));
    return (*env)->NewStringUTF(env, utf_text);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_setBigFontFile(JNIEnv *env, jobject job, jlong ref, jstring bigFontFile) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return;
    }
    const char *bigFontFileStr = (*env)->GetStringUTFChars(env, bigFontFile, NULL);
    if (bigFontFileStr == NULL) {
        return;
    }
    char gbk_text[200];
    utf8_to_gbk(bigFontFileStr, gbk_text, sizeof(gbk_text));
    (*env)->ReleaseStringUTFChars(env, bigFontFile, bigFontFileStr);
    style->bigfont_file = (BITCODE_TV) gbk_text;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectStyle_getBigFontFile(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_STYLE *style = (Dwg_Object_STYLE*)(intptr_t)ref;
    if (style == NULL) {
        return NULL;
    }
    char *c_text = (char *) style->bigfont_file;
    if (c_text == NULL) {
        return NULL;
    }
    char utf_text[200];
    gbk_to_utf8(c_text, utf_text, sizeof(utf_text));
    return (*env)->NewStringUTF(env, utf_text);
}
