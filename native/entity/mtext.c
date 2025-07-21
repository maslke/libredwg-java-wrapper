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


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_entity_MText_setText(JNIEnv *env, jobject job, jlong ref, jstring value) {
    Dwg_Entity_MTEXT *text_entity = (Dwg_Entity_MTEXT*)(intptr_t)ref;
    if (text_entity == NULL) {
        return;
    }
    char gbk_text[200];
    const char *chars = (*env)->GetStringUTFChars(env, value, NULL);
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    text_entity->text = strdup(gbk_text);
    (*env)->ReleaseStringUTFChars(env, value, chars);
}
