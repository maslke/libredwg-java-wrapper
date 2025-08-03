#include <jni.h>
#include <stdio.h>
#include "objectlayer.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "dwg.h"
#include "helper.h"

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->flag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFlag(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->flag = flag;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getName(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->name == NULL) {
        return NULL;
    }
    char utf_chars[256];
    gbk_to_utf8(layer->name, utf_chars, sizeof(utf_chars));
    return (*env)->NewStringUTF(env, utf_chars);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setName(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || name == NULL) {
        return;
    }
    const char *nameStr = (*env)->GetStringUTFChars(env, name, NULL);
    char utf_chars[256];
    utf8_to_gbk(nameStr, utf_chars, sizeof(utf_chars));
    if (layer->name != NULL) {
        free(layer->name);
    }
    layer->name = strdup(utf_chars);
    (*env)->ReleaseStringUTFChars(env, name, nameStr);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setUsed(JNIEnv *env, jobject obj, jlong ref, jint used) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->used = used;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getUsed(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->used;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefRef(JNIEnv *env, jobject obj, jlong ref, jint isXrefRef) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->is_xref_ref = isXrefRef;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefRef(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->is_xref_ref;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefResolved(JNIEnv *env, jobject obj, jlong ref, jint isXrefResolved) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->is_xref_resolved = isXrefResolved;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefResolved(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->is_xref_resolved;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setIsXrefDep(JNIEnv *env, jobject obj, jlong ref, jint isXrefDep) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->is_xref_dep = isXrefDep;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getIsXrefDep(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->is_xref_dep;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setXref(JNIEnv *env, jobject obj, jlong ref, jobject xref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || xref == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, xref);
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong xrefRef = (*env)->GetLongField(env, xref, refField);
    layer->xref = (Dwg_Object_Ref*)(intptr_t)xrefRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getXref(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->xref == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, layer->xref);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getParent(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->parent == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgObjectObject";
    Dwg_Object_Object *object_obj = (Dwg_Object_Object*)layer->parent;
    return create_object(env, class_name, (jlong)(intptr_t)object_obj);
}
 
JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFlag0(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->flag0;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFlag0(JNIEnv *env, jobject obj, jlong ref, jint flag) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->flag0 = flag;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFrozen(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->frozen;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFrozen(JNIEnv *env, jobject obj, jlong ref, jint frozen) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->frozen = frozen;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setOn(JNIEnv *env, jobject obj, jlong ref, jint on) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->on = on;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getOn(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->on;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getFrozenInNew(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->frozen_in_new;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setFrozenInNew(JNIEnv *env, jobject obj, jlong ref, jint frozenInNew) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->frozen_in_new = frozenInNew;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLocked(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->locked;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLocked(JNIEnv *env, jobject obj, jlong ref, jint locked) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->locked = locked;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getPlotFlag(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0;
    }
    return layer->plotflag;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setPlotFlag(JNIEnv *env, jobject obj, jlong ref, jint plotFlag) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->plotflag = plotFlag;
}

JNIEXPORT jdouble JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLinewt(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return 0.0;
    }
    return layer->linewt;
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLinewt(JNIEnv *env, jobject obj, jlong ref, jdouble linewt) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return;
    }
    layer->linewt = linewt;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getColor(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/obj/DwgColor";
    Dwg_Color *color_obj = (Dwg_Color*)&layer->color;
    return create_object(env, class_name, (jlong)(intptr_t)color_obj);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setColor(JNIEnv *env, jobject obj, jlong ref, jobject color) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || color == NULL) {
        return;
    }
    
    jclass colorclass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgColor");
    if (colorclass == NULL) {
        return;
    }
    jmethodID refMethod = (*env)->GetMethodID(env, colorclass, "getRef", "()J");
    if (refMethod == NULL) {
        (*env)->DeleteLocalRef(env, colorclass);
        return;
    }
    jlong colorRef = (*env)->CallLongMethod(env, color, refMethod);
    Dwg_Color *color_obj = (Dwg_Color*)(intptr_t)colorRef;
    layer->color = *color_obj;
    (*env)->DeleteLocalRef(env, colorclass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getPlotStyle(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->plotstyle == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, layer->plotstyle);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setPlotStyle(JNIEnv *env, jobject obj, jlong ref, jobject plotStyle) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || plotStyle == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, plotStyle);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong plotStyleRef = (*env)->GetLongField(env, plotStyle, refField);
    layer->plotstyle = (Dwg_Object_Ref*)(intptr_t)plotStyleRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getMaterial(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->material == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, layer->material);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setMaterial(JNIEnv *env, jobject obj, jlong ref, jobject material) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || material == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, material);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong materialRef = (*env)->GetLongField(env, material, refField);
    layer->material = (Dwg_Object_Ref*)(intptr_t)materialRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getLtype(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->ltype == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, layer->ltype);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setLtype(JNIEnv *env, jobject obj, jlong ref, jobject ltype) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || ltype == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, ltype);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong ltypeRef = (*env)->GetLongField(env, ltype, refField);
    layer->ltype = (Dwg_Object_Ref*)(intptr_t)ltypeRef;
    (*env)->DeleteLocalRef(env, refClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_getVisualStyle(JNIEnv *env, jobject obj, jlong ref) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || layer->visualstyle == NULL) {
        return NULL;
    }
    return createDwgObjectRef(env, layer->visualstyle);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectLayer_setVisualStyle(JNIEnv *env, jobject obj, jlong ref, jobject visualStyle) {
    Dwg_Object_LAYER *layer = (Dwg_Object_LAYER*)(intptr_t)ref;
    if (layer == NULL || visualStyle == NULL) {
        return;
    }
    jclass refClass = (*env)->GetObjectClass(env, visualStyle);
    if (refClass == NULL) {
        return;
    }
    jfieldID refField = (*env)->GetFieldID(env, refClass, "ref", "J");
    jlong visualStyleRef = (*env)->GetLongField(env, visualStyle, refField);
    layer->visualstyle = (Dwg_Object_Ref*)(intptr_t)visualStyleRef;
    (*env)->DeleteLocalRef(env, refClass);
}

