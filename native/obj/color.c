#include <jni.h>
#include <stdio.h>
#include "color.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setIndex(JNIEnv *env, jobject obj, jlong ref, jint index) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->index = index;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->flag = flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setRaw(JNIEnv *env, jobject obj, jlong ref, jint raw) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->raw = raw;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setRgb(JNIEnv *env, jobject obj, jlong ref, jint rgb) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->rgb = rgb;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setMethod(JNIEnv *env, jobject obj, jlong ref, jint method) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->method = method;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setName(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    const char *chars = (*env)->GetStringUTFChars(env, name, NULL);
    if (chars == NULL) {
        return;
    }
    char utf_chars[256];
    utf8_to_gbk(chars, utf_chars, sizeof(utf_chars));
    color->name = strdup(utf_chars);
    (*env)->ReleaseStringUTFChars(env, name, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setBookName(JNIEnv *env, jobject obj, jlong ref, jstring bookName) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    const char *chars = (*env)->GetStringUTFChars(env, bookName, NULL);
    if (chars == NULL) {
        return;
    }
    char utf_chars[256];
    utf8_to_gbk(chars, utf_chars, sizeof(utf_chars));
    color->book_name = strdup(utf_chars);
    (*env)->ReleaseStringUTFChars(env, bookName, chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setHandle(JNIEnv *env, jobject obj, jlong ref, jobject handle) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    if (handle == NULL) {
        return;
    }
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    jmethodID getRef = (*env)->GetMethodID(env, refClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, handle, getRef);
    if (reference == 0) {
        return;
    }
    color->handle = (Dwg_Object_Ref *)(intptr_t)reference;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlphaRaw(JNIEnv *env, jobject obj, jlong ref, jint alphaRaw) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->alpha_raw = alphaRaw;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlphaType(JNIEnv *env, jobject obj, jlong ref, jshort alphaType) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->alpha_type = alphaType;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgColor_setAlpha(JNIEnv *env, jobject obj, jlong ref, jint alpha) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return;
    }
    color->alpha = alpha;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getIndex(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->index;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getRaw(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->raw;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getRgb(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->rgb;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getMethod(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->method;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getName(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return NULL;
    }
    char *chars = color->name;
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getBookName(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return NULL;
    }
    char *chars = color->book_name;
    if (chars == NULL) {
        return NULL;
    }
    char utf_chars[256];
    gbk_to_utf8(chars, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getHandle(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *handle = color->handle;
    return createDwgObjectRef(env, handle);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlphaRaw(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->alpha_raw;
}

JNIEXPORT jshort JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlphaType(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->alpha_type;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgColor_getAlpha(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Color *color = (Dwg_Color *)(intptr_t)ref;
    if (color == NULL) {
        return 0;
    }
    return color->alpha;
}
