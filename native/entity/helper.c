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
#include "cjson/cJSON.h"


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
    jclass refClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (refClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, refClass, "<init>", "()V");
    jobject refObj = (*env)->NewObject(env, refClass, constructor);

    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jfieldID absoluteRefField = (*env)->GetFieldID(env, refClass, "absoluteRef", "J");
    jfieldID r11IdxField = (*env)->GetFieldID(env, refClass, "r11Idx", "S");
    (*env)->SetLongField(env, refObj, refField, (jlong)(intptr_t)style);
    (*env)->SetLongField(env, refObj, absoluteRefField, style->absolute_ref);
    (*env)->SetShortField(env, refObj, r11IdxField, style->r11_idx);
    // TODO set DwgHandle
    return refObj;
   }
