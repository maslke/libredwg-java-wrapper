#include <jni.h>
#include <stdio.h>
#include "endblk.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"

JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_entity_EndBlk_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Entity_ENDBLK *blk_entity = (Dwg_Entity_ENDBLK*)(intptr_t)ref;
    if (blk_entity == NULL) {
        return 0;
    }
    return (jlong)(intptr_t)blk_entity->parent;
}
