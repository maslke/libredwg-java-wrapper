#include <jni.h>
#include <stdio.h>
#include <dwg.h>
#include <dwg_api.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include <iconv.h>
#include <ctype.h>
#include <math.h>
#include "cjson/cJSON.h"

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_Dwg_getVersion
  (JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "0.0.1");
}


JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_createDocument(JNIEnv *env, jobject obj) {
    Dwg_Data *dwg_data = dwg_new_Document(R_2000, 0, 0);
    return (jlong)(intptr_t)dwg_data;
}

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_Dwg_openDocument(JNIEnv *env, jobject obj, jstring filename) {
    Dwg_Data *dwg_data = (Dwg_Data *) malloc(sizeof(Dwg_Data));
    memset(dwg_data, 0, sizeof(Dwg_Data));
    dwg_read_file(filename, dwg_data);
    return (jlong)(intptr_t)dwg_data;
}

