#include <jni.h>
#include <stdio.h>
#include "helper.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>

void log_info(JNIEnv* env, const char* message) {
    if (env == NULL || message == NULL) {
        return;
    }
    jclass systemClass = (*env)->FindClass(env, "java/lang/System");
    jfieldID outField = (*env)->GetStaticFieldID(env, systemClass, "out", "Ljava/io/PrintStream;");
    jobject out = (*env)->GetStaticObjectField(env, systemClass, outField);

    jclass printStreamClass = (*env)->FindClass(env, "java/io/PrintStream");
    jmethodID printlnMethod = (*env)->GetMethodID(env, printStreamClass, "println", "(Ljava/lang/String;)V");

    jstring jMessage = (*env)->NewStringUTF(env, message);
    (*env)->CallVoidMethod(env, out, printlnMethod, jMessage);
    (*env)->DeleteLocalRef(env, jMessage);
}


// helper function
BITCODE_RC dxf_find_lweight(const int lw) {
    // See acdb.h: 100th of a mm, enum of
    const int lweights[] = {0,
                            5,
                            9,
                            13,
                            15,
                            18,
                            20,
                            25,
                            30,
                            35,
                            40,
                            50,
                            53,
                            60,
                            70,
                            80,
                            90,
                            100,
                            106,
                            120,
                            140,
                            158,
                            200,
                            211,
                            0,
                            0,
                            0,
                            0,
                            0,
                            -1,         // BYLAYER
                            -2,         // BYBLOCK
                            -3};        // BYLWDEFAULT
    for (int i = 0; i < 32; i++) {
        if (lweights[i] == lw)
            return i;
    }
    return 0;
}


int find_linewt_by_index(const int lw) {
    // See acdb.h: 100th of a mm, enum of
    const int lweights[] = {0,
                            5,
                            9,
                            13,
                            15,
                            18,
                            20,
                            25,
                            30,
                            35,
                            40,
                            50,
                            53,
                            60,
                            70,
                            80,
                            90,
                            100,
                            106,
                            120,
                            140,
                            158,
                            200,
                            211,
                            0,
                            0,
                            0,
                            0,
                            0,
                            -1,         // BYLAYER
                            -2,         // BYBLOCK
                            -3};        // BYLWDEFAULT
    int len = sizeof(lweights) / sizeof(int);
    if(lw < len) {
        return lweights[lw];
    }
    return 0;
}

int utf8_to_gbk(const char *in_str, char *out_buf, size_t out_len) {
    iconv_t cd = iconv_open("GBK", "UTF-8");
    if (cd == (iconv_t) -1) {
        perror("iconv_open");
        return -1;
    }
    size_t in_len = strlen(in_str);
    char *in_ptr = (char *) in_str;
    char *out_ptr = out_buf;
    size_t out_left = out_len;
    if (iconv(cd, &in_ptr, &in_len, &out_ptr, &out_left) == (size_t) -1) {
        perror("iconv");
        iconv_close(cd);
        return -1;
    }
    iconv_close(cd);
    *out_ptr = '\0';
    return 0;
}

int gbk_to_utf8(const char *in_str, char *out_buf, size_t out_len) {
    if (!in_str || !out_buf || out_len == 0) {
        return -1;
    }

    iconv_t cd = iconv_open("UTF-8", "GBK");
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        return -1;
    }

    size_t in_bytes_left = strlen(in_str);
    size_t out_bytes_left = out_len - 1;
    char *in_buf = (char *)in_str;
    char *out_ptr = out_buf;

    size_t ret = iconv(cd, &in_buf, &in_bytes_left, &out_ptr, &out_bytes_left);
    if (ret == (size_t)-1) {
        perror("iconv");
        iconv_close(cd);
        return -1;
    }

    *out_ptr = '\0';
    iconv_close(cd);
    return 0;
}

jobject createDwgObjectRef(JNIEnv *env, Dwg_Object_Ref *style) {
    if (style == NULL) {
        return NULL;
    }
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, refClass, "<init>", "()V");
    jobject refObj = (*env)->NewObject(env, refClass, constructor);

    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    (*env)->SetLongField(env, refObj, refField, (jlong)(intptr_t)style);
    (*env)->DeleteLocalRef(env, refClass);
    return refObj;
}

jobject createDwgColor(JNIEnv *env, Dwg_Color *color) {
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgColor");
    if (refClass == NULL) {
        return NULL;
    }
    if (color == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, refClass, "<init>", "()V");
    jobject refObj = (*env)->NewObject(env, refClass, constructor);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    (*env)->SetLongField(env, refObj, refField, (jlong)(intptr_t)color);
    jmethodID indexMethod = (*env)->GetMethodID(env, refClass, "setIndex", "(I)V");
    jmethodID flagMethod = (*env)->GetMethodID(env, refClass, "setFlag", "(I)V");
    jmethodID rawMethod = (*env)->GetMethodID(env, refClass, "setRaw", "(I)V");
    jmethodID rgbMethod = (*env)->GetMethodID(env, refClass, "setRgb", "(I)V");
    jmethodID methodMethod = (*env)->GetMethodID(env, refClass, "setMethod", "(I)V");
    jmethodID nameMethod = (*env)->GetMethodID(env, refClass, "setName", "(Ljava/lang/String;)V");
    jmethodID bookNameMethod = (*env)->GetMethodID(env, refClass, "setBookName", "(Ljava/lang/String;)V");
    jmethodID handleMethod = (*env)->GetMethodID(env, refClass, "setHandle", "(Lio/github/maslke/dwg/obj/DwgObjectRef;)V");
    jmethodID alphaRawMethod = (*env)->GetMethodID(env, refClass, "setAlphaRaw", "(I)V");
    jmethodID alphaTypeMethod = (*env)->GetMethodID(env, refClass, "setAlphaType", "(S)V");
    jmethodID alphaMethod = (*env)->GetMethodID(env, refClass, "setAlpha", "(I)V");
    (*env)->CallVoidMethod(env, refObj, indexMethod, color->index);
    (*env)->CallVoidMethod(env, refObj, flagMethod, color->flag);
    (*env)->CallVoidMethod(env, refObj, rawMethod, color->raw);
    (*env)->CallVoidMethod(env, refObj, rgbMethod, color->rgb);
    
    if (color->name != NULL) {
        jstring nameStr = (*env)->NewStringUTF(env, color->name);
        if (nameStr != NULL) {
            (*env)->CallVoidMethod(env, refObj, 
                nameMethod, 
                nameStr);
            (*env)->DeleteLocalRef(env, nameStr);
        }
    }

    if (color->book_name != NULL) {
        jstring bookNameStr = (*env)->NewStringUTF(env, color->book_name);
        if (bookNameStr != NULL) {
            (*env)->CallVoidMethod(env, refObj, 
                bookNameMethod, 
                bookNameStr);
            (*env)->DeleteLocalRef(env, bookNameStr);
        }
    }

    (*env)->CallVoidMethod(env, refObj, handleMethod, createDwgObjectRef(env, color->handle));
    (*env)->CallVoidMethod(env, refObj, alphaRawMethod, color->alpha_raw);
    (*env)->CallVoidMethod(env, refObj, alphaTypeMethod, color->alpha_type);
    (*env)->CallVoidMethod(env, refObj, alphaMethod, color->alpha);
    (*env)->DeleteLocalRef(env, refClass);
    return refObj;
}

jobject create_object(JNIEnv *env, const char* class_names, jlong ref) {
    jclass class = (*env)->FindClass(env, class_names);
    if (class == NULL) {
        return NULL;
    }
    if (ref == 0) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, class, "<init>", "()V");
    jobject obj = (*env)->NewObject(env, class, constructor);
    jfieldID refField = (*env)->GetFieldID(env, class, "ref", "J");
    (*env)->SetLongField(env, obj, refField, ref);
    (*env)->DeleteLocalRef(env, class);
    return obj;
}