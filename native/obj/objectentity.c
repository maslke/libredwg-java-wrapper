#include <jni.h>
#include <stdio.h>
#include "objectentity.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setColor(JNIEnv *env, jobject job, jlong ref, jobject color) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass colorClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgColor");
    if (colorClass == NULL) {
        return;
    }
    jmethodID refMethod = (*env)->GetMethodID(env, colorClass, "getRef", "()J");
    jlong reference = (*env)->CallLongMethod(env, color, refMethod);
    if (reference > 0) {

        Dwg_Color *ref_color = (Dwg_Color *)(intptr_t)reference;
        entity->color = *ref_color;
    }
    else {
        jmethodID indexMethod = (*env)->GetMethodID(env, colorClass, "getIndex", "()I");
        jint index = (*env)->CallIntMethod(env, color, indexMethod);
        entity->color.index = index;
    }
    (*env)->DeleteLocalRef(env, colorClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLinewt(JNIEnv *env, jobject job, jlong ref, jint linewt) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    entity->linewt = dxf_find_lweight(linewt);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLtype(JNIEnv *env, jobject job, jlong ref, jobject ltype) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (styleClass == NULL) {
        return;
    }
    jmethodID styleMethod = (*env)->GetMethodID(env, styleClass, "getRef", "()J");
    if (styleMethod == NULL) {
        (*env)->DeleteLocalRef(env, styleClass);
        return;
    }
    jlong ltype_ref = (*env)->CallLongMethod(env, ltype, styleMethod);
    entity->ltype = (Dwg_Object_Ref*)(intptr_t)ltype_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_setLayer(JNIEnv *env, jobject job, jlong ref, jobject layer) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return;
    }
    jclass styleClass = (*env)->FindClass(env, "io/github/maslke/dwg/obj/DwgObjectRef");
    if (styleClass == NULL) {
        return;
    }
    jmethodID styleMethod = (*env)->GetMethodID(env, styleClass, "getRef", "()J");
    if (styleMethod == NULL) {
        (*env)->DeleteLocalRef(env, styleClass);
        return;
    }
    jlong layer_ref = (*env)->CallLongMethod(env, layer, styleMethod);
    entity->layer = (Dwg_Object_Ref*)(intptr_t)layer_ref;
    (*env)->DeleteLocalRef(env, styleClass);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getDwg(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    jclass dwgClass = (*env)->FindClass(env, "io/github/maslke/dwg/Dwg");
    if (dwgClass == NULL) {
        return NULL;
    }
    jmethodID dwgConstructor = (*env)->GetMethodID(env, dwgClass, "<init>", "()V");
    if (dwgConstructor == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    jobject dwg = (*env)->NewObject(env, dwgClass, dwgConstructor);
    if (dwg == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    jfieldID refField = (*env)->GetFieldID(env, dwgClass, "ref", "J");
    if (refField == NULL) {
        (*env)->DeleteLocalRef(env, dwgClass);
        return NULL;
    }
    (*env)->SetLongField(env, dwg, refField, (jlong)entity->dwg);
    (*env)->DeleteLocalRef(env, dwgClass);
    return dwg;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getColor(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    return createDwgColor(env, &entity->color);
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLinewt(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    int type = entity->linewt;
    return find_linewt_by_index(type);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLayer(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *layer = entity->layer;
    return createDwgObjectRef(env, layer);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getLtype(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Object_Ref *ltype = entity -> ltype;
    return createDwgObjectRef(env, ltype);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityPoint(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_POINT *point = entity->tio.POINT;
    if (point == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Point";
    return create_object(env, class_name, (jlong)(intptr_t)point);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityLine(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_LINE *line = entity->tio.LINE;
    if (line == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Line";
    return create_object(env, class_name, (jlong)(intptr_t)line);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityArc(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_ARC *arc = entity->tio.ARC;
    if (arc == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Arc";
    return create_object(env, class_name, (jlong)(intptr_t)arc);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityCircle(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_CIRCLE *circle = entity->tio.CIRCLE;
    if (circle == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Circle";
    return create_object(env, class_name, (jlong)(intptr_t)circle);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityText(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_TEXT *text = entity->tio.TEXT;
    if (text == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Text";
    return create_object(env, class_name, (jlong)(intptr_t)text);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityEllipse(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_ELLIPSE *ellipse = entity->tio.ELLIPSE;
    if (ellipse == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Ellipse";
    return create_object(env, class_name, (jlong)(intptr_t)ellipse);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntitySpline(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_SPLINE *spline = entity->tio.SPLINE;
    if (spline == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Spline";
    return create_object(env, class_name, (jlong)(intptr_t)spline);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityInsert(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_INSERT *insert = entity->tio.INSERT;
    if (insert == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Insert";
    return create_object(env, class_name, (jlong)(intptr_t)insert);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityMLine(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_MLINE *mline = entity->tio.MLINE;
    if (mline == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/MLine";
    return create_object(env, class_name, (jlong)(intptr_t)mline);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityHatch(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_HATCH *hatch = entity->tio.HATCH;
    if (hatch == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Hatch";
    return create_object(env, class_name, (jlong)(intptr_t)hatch);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityLwpolyline(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_LWPOLYLINE *lwpolyline = entity->tio.LWPOLYLINE;
    if (lwpolyline == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Lwpolyline";
    return create_object(env, class_name, (jlong)(intptr_t)lwpolyline);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityBlock(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_BLOCK *block = entity->tio.BLOCK;
    if (block == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Block";
    return create_object(env, class_name, (jlong)(intptr_t)block);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityEndBlk(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_ENDBLK *endblk = entity->tio.ENDBLK;
    if (endblk == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/EndBlk";
    return create_object(env, class_name, (jlong)(intptr_t)endblk);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityImage(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_IMAGE *image = entity->tio.IMAGE;
    if (image == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Image";
    return create_object(env, class_name, (jlong)(intptr_t)image);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityMInsert(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_MINSERT *minsert = entity->tio.MINSERT;
    if (minsert == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/MInsert";
    return create_object(env, class_name, (jlong)(intptr_t)minsert);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityPolyline2d(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_POLYLINE_2D *polyline2d = entity->tio.POLYLINE_2D;
    if (polyline2d == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Polyline2d";
    return create_object(env, class_name, (jlong)(intptr_t)polyline2d);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityPolyline3d(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_POLYLINE_3D *polyline3d = entity->tio.POLYLINE_3D;
    if (polyline3d == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Polyline3d";
    return create_object(env, class_name, (jlong)(intptr_t)polyline3d);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityOleFrame(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_OLEFRAME *oleframe = entity->tio.OLEFRAME;
    if (oleframe == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/OleFrame";
    return create_object(env, class_name, (jlong)(intptr_t)oleframe);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntityRay(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return NULL;
    }
    Dwg_Entity_RAY *ray = entity->tio.RAY;
    if (ray == NULL) {
        return NULL;
    }
    const char *class_name = "io/github/maslke/dwg/entity/Ray";
    return create_object(env, class_name, (jlong)(intptr_t)ray);
}



JNIEXPORT jlong JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getObjId(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    return entity->objid;
}

JNIEXPORT jint JNICALL Java_io_github_maslke_dwg_obj_DwgObjectEntity_getEntMode(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_Entity *entity = (Dwg_Object_Entity*)(intptr_t)ref;
    if (entity == NULL) {
        return 0;
    }
    return entity->entmode;
}
