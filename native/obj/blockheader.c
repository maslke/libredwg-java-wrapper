#include <jni.h>
#include <stdio.h>
#include "blockheader.h"
#include <dwg_api.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <iconv.h>
#include "helper.h"


JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPoint(JNIEnv *env, jobject obj, jlong ref, jobject point) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, point);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d pt = {.x = x, .y = y, .z = z};
    Dwg_Entity_POINT *point_entity =  dwg_add_POINT(hdr, &pt);
    jlong reference = (jlong)(intptr_t)point_entity;
    if (reference == 0) {
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Point");
    if (pointClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, pointClass, "<init>", "(J)V");
    jobject pointObj = (*env)->NewObject(env, pointClass, constructor, reference);
    (*env)->DeleteLocalRef(env, pointClass);
    return pointObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLine(JNIEnv *env, jobject obj, jlong ref,
jobject start, jobject end) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, start);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble start_x = (*env)->GetDoubleField(env, start, fidX);
    jdouble start_y = (*env)->GetDoubleField(env, start, fidY);
    jdouble start_z = (*env)->GetDoubleField(env, start, fidZ);

    dwg_point_3d start_point = {.x = start_x, .y = start_y, .z = start_z};

    jdouble end_x = (*env)->GetDoubleField(env, end, fidX);
    jdouble end_y = (*env)->GetDoubleField(env, end, fidY);
    jdouble end_z = (*env)->GetDoubleField(env, end, fidZ);
    dwg_point_3d end_point = {.x = end_x, .y = end_y, .z = end_z};
    Dwg_Entity_LINE *line_entity = dwg_add_LINE(hdr, &start_point, &end_point);
    if (line_entity == NULL) {
        return NULL;
    }
    jlong reference = (jlong)(intptr_t)line_entity;
    jclass lineClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Line");
    if (lineClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, lineClass, "<init>", "(J)V");
    jobject lineObj = (*env)->NewObject(env, lineClass, constructor, reference);
    (*env)->DeleteLocalRef(env, lineClass);
    return lineObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addText(JNIEnv *env, jobject job, jlong ref, jstring text_value, jobject ins_pt, jdouble height) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char *chars = (*env)->GetStringUTFChars(env, text_value, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    jclass clazz = (*env)->GetObjectClass(env, ins_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble ins_x = (*env)->GetDoubleField(env, ins_pt, fidX);
    jdouble ins_y = (*env)->GetDoubleField(env, ins_pt, fidY);
    jdouble ins_z = (*env)->GetDoubleField(env, ins_pt, fidZ);

    dwg_point_3d insert_pt = { .x = ins_x, .y = ins_y, .z = ins_z };
    Dwg_Entity_TEXT *text_entity = dwg_add_TEXT(hdr, strdup(gbk_text), &insert_pt, height);
    jlong reference = (jlong)(intptr_t)text_entity;
    jclass textClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Text");
    if (textClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, textClass, "<init>", "(J)V");
    jobject textObj = (*env)->NewObject(env, textClass, constructor, reference);
    (*env)->DeleteLocalRef(env, textClass);
    return textObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addMText(JNIEnv *env, jobject job, jlong ref, jstring text_value, jobject ins_pt, jdouble rect_width) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char *chars = (*env)->GetStringUTFChars(env, text_value, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    jclass clazz = (*env)->GetObjectClass(env, ins_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble ins_x = (*env)->GetDoubleField(env, ins_pt, fidX);
    jdouble ins_y = (*env)->GetDoubleField(env, ins_pt, fidY);
    jdouble ins_z = (*env)->GetDoubleField(env, ins_pt, fidZ);
    dwg_point_3d insert_pt = { .x = ins_x, .y = ins_y, .z = ins_z };
    Dwg_Entity_MTEXT *mtext_entity = dwg_add_MTEXT(hdr, &insert_pt, rect_width, strdup(gbk_text));
    jlong reference = (jlong)(intptr_t)mtext_entity;
    jclass mtextClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/MText");
    if (mtextClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, mtextClass, "<init>", "(J)V");
    jobject mtextObj = (*env)->NewObject(env, mtextClass, constructor, reference);
    (*env)->DeleteLocalRef(env, mtextClass);
    return mtextObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addCircle(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_CIRCLE *circle_entity = dwg_add_CIRCLE(hdr, &center_pt, radius);
    jlong reference = (jlong)(intptr_t)circle_entity;
    jclass circleClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Circle");
    if (circleClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, circleClass, "<init>", "(J)V");
    jobject circleObj = (*env)->NewObject(env, circleClass, constructor, reference);
    return circleObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addArc(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble radius, jdouble start_angle, jdouble end_angle) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ARC *arc_entity = dwg_add_ARC(hdr, &center_pt, radius, start_angle, end_angle);
    jlong reference = (jlong)(intptr_t)arc_entity;

    jclass arcClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Arc");
    if (arcClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, arcClass, "<init>", "(J)V");
    jobject arcObj = (*env)->NewObject(env, arcClass, constructor, reference);
    (*env)->DeleteLocalRef(env, arcClass);
    return arcObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEllipse(JNIEnv *env, jobject job, jlong ref, jobject center, jdouble majorAxis, jdouble axisRatio) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, center);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble center_x = (*env)->GetDoubleField(env, center, fidX);
    jdouble center_y = (*env)->GetDoubleField(env, center, fidY);
    jdouble center_z = (*env)->GetDoubleField(env, center, fidZ);
    dwg_point_3d center_pt = {.x = center_x, .y = center_y, .z = center_z};
    Dwg_Entity_ELLIPSE *ellipse_entity = dwg_add_ELLIPSE(hdr, &center_pt, majorAxis, axisRatio);
    jlong reference = (jlong)(intptr_t)ellipse_entity;
    jclass ellipseClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Ellipse");
    if (ellipseClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, ellipseClass, "<init>", "(J)V");
    jobject ellipseObj = (*env)->NewObject(env, ellipseClass, constructor, reference);
    (*env)->DeleteLocalRef(env, ellipseClass);
    return ellipseObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addInsert(JNIEnv *env, jobject job, jlong ref, jobject insert_pt, jstring block_name, jdouble scale_x, jdouble scale_y, jdouble scale_z, jdouble rotation) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass clazz = (*env)->GetObjectClass(env, insert_pt);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, insert_pt, fidX);
    jdouble y = (*env)->GetDoubleField(env, insert_pt, fidY);
    jdouble z = (*env)->GetDoubleField(env, insert_pt, fidZ);
    dwg_point_3d ins_pt = {.x = x, .y = y, .z = z};
    const char* chars = (*env)->GetStringUTFChars(env, block_name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Entity_INSERT *insert_entity = dwg_add_INSERT(hdr, &ins_pt, strdup(gbk_text), scale_x, scale_y, scale_z, rotation);
    (*env)->ReleaseStringUTFChars(env, block_name, chars);
    jclass insertClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Insert");
    if (insertClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, insertClass, "<init>", "(J)V");
    jobject insertObj = (*env)->NewObject(env, insertClass, constructor, (jlong)(intptr_t)insert_entity);
    (*env)->DeleteLocalRef(env, insertClass);
    return insertObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addBlock(JNIEnv *env, jobject obj, jlong ref, jstring name) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Entity_BLOCK *block = dwg_add_BLOCK(hdr, strdup(gbk_text));
    if (block == NULL) {
        return NULL;
    }
    (*env)->ReleaseStringUTFChars(env, name, chars);
    jclass blockClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Block");
    if (blockClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, blockClass, "<init>", "(J)V");
    jobject blockObj = (*env)->NewObject(env, blockClass, constructor, (jlong)(intptr_t)block);
    (*env)->DeleteLocalRef(env, blockClass);
    return blockObj;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addEndBlk(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    Dwg_Entity_ENDBLK *endblk_entity = dwg_add_ENDBLK(hdr);
    if (endblk_entity == NULL) {
        return NULL;
    }
    jclass blkClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/EndBlk");
    if (blkClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, blkClass, "<init>", "(J)V");
    jobject blkObj = (*env)->NewObject(env, blkClass, constructor, (jlong)(intptr_t)endblk_entity);
    (*env)->DeleteLocalRef(env, blkClass);
    return blkObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addLwpolyline(JNIEnv *env, jobject job, jlong ref, jobject pointList) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    jclass listClass = (*env)->GetObjectClass(env, pointList);
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint num_points = (*env)->CallIntMethod(env, pointList, sizeMethod);
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    dwg_point_2d *pnts = malloc(sizeof(dwg_point_2d) * num_points);
    for (int i = 0; i < num_points; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        pnts[i].x = x;
        pnts[i].y = y;
    }
    Dwg_Entity_LWPOLYLINE *lwpolyline = dwg_add_LWPOLYLINE(hdr, num_points, pnts);
    jlong reference = (jlong)(intptr_t)lwpolyline;
    jclass lwpolylineClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Lwpolyline");
    if (lwpolylineClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, lwpolylineClass, "<init>", "(J)V");
    jobject lwpolylineObj = (*env)->NewObject(env, lwpolylineClass, constructor, reference);
    (*env)->DeleteLocalRef(env, lwpolylineClass);
    return lwpolylineObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addRay(JNIEnv *env, jobject job, jlong ref, jobject point, jobject vector) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return NULL;
    }
    if (vector == NULL) {
        return NULL;
    }

    jclass clazz = (*env)->GetObjectClass(env, point);
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d pt = {.x = x, .y = y, .z = z};
    jclass vectorClass = (*env)->GetObjectClass(env, vector);
    jfieldID vectorXField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID vectorYField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID vectorZField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble vectorX = (*env)->GetDoubleField(env, vector, vectorXField);
    jdouble vectorY = (*env)->GetDoubleField(env, vector, vectorYField);
    jdouble vectorZ = (*env)->GetDoubleField(env, vector, vectorZField);
    dwg_point_3d vec = {.x = vectorX, .y = vectorY, .z = vectorZ};
    Dwg_Entity_RAY *ray = dwg_add_RAY(hdr, &pt, &vec);
    jlong reference = (jlong)(intptr_t)ray;
    if (reference == 0) {
        return NULL;
    }
    jclass rayClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Ray");
    if (rayClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, rayClass, "<init>", "(J)V");
    jobject rayObj = (*env)->NewObject(env, rayClass, constructor, reference);
    (*env)->DeleteLocalRef(env, rayClass);
    return rayObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addSolid(JNIEnv *env, jobject job, jlong ref, jobject corner1, jobject corner2, jobject corner3, jobject corner4) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || corner1 == NULL || corner2 == NULL || corner3 == NULL || corner4 == NULL) {
        return NULL;
    }
    jclass clazz = (*env)->GetObjectClass(env, corner1);
    if (clazz == NULL) {
        return NULL;
    }
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble corner1_x = (*env)->GetDoubleField(env, corner1, fidX);
    jdouble corner1_y = (*env)->GetDoubleField(env, corner1, fidY);
    jdouble corner1_z = (*env)->GetDoubleField(env, corner1, fidZ);
    dwg_point_3d corner1_pt = {.x = corner1_x, .y = corner1_y, .z = corner1_z};
    jclass corner2Class = (*env)->GetObjectClass(env, corner2);
    if (corner2Class == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        return NULL;
    }
    jfieldID corner2XField = (*env)->GetFieldID(env, corner2Class, "x", "D");
    jfieldID corner2YField = (*env)->GetFieldID(env, corner2Class, "y", "D");
    jdouble corner2_x = (*env)->GetDoubleField(env, corner2, corner2XField);
    jdouble corner2_y = (*env)->GetDoubleField(env, corner2, corner2YField);
    dwg_point_2d corner2_pt = {.x = corner2_x, .y = corner2_y};
    jdouble corner3_x = (*env)->GetDoubleField(env, corner3, corner2XField);
    jdouble corner3_y = (*env)->GetDoubleField(env, corner3, corner2YField);
    dwg_point_2d corner3_pt = {.x = corner3_x, .y = corner3_y};
    jdouble corner4_x = (*env)->GetDoubleField(env, corner4, corner2XField);
    jdouble corner4_y = (*env)->GetDoubleField(env, corner4, corner2YField);
    dwg_point_2d corner4_pt = {.x = corner4_x, .y = corner4_y};
    Dwg_Entity_SOLID *solid = dwg_add_SOLID(hdr, &corner1_pt, &corner2_pt, &corner3_pt, &corner4_pt);
    jlong reference = (jlong)(intptr_t)solid;
    jclass solidClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Solid");
    if (solidClass == NULL) {
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, solidClass, "<init>", "(J)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        (*env)->DeleteLocalRef(env, corner2Class);
        (*env)->DeleteLocalRef(env, solidClass);
        return NULL;
    }
    jobject solidObj = (*env)->NewObject(env, solidClass, constructor, reference);
    (*env)->DeleteLocalRef(env, clazz);
    (*env)->DeleteLocalRef(env, corner2Class);
    (*env)->DeleteLocalRef(env, solidClass);
    return solidObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addShape(JNIEnv *env, jobject job, jlong ref, jstring name, jobject point, jdouble scale, jdouble obliqueAngle) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || point == NULL) {
        return NULL;
    }
    jclass clazz = (*env)->GetObjectClass(env, point);
    if (clazz == NULL) {
        return NULL;
    }
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d ins_pt = {.x = x, .y = y, .z = z};
    const char* chars = (*env)->GetStringUTFChars(env, name, NULL);
    char gbk_text[200];
    utf8_to_gbk(chars, gbk_text, sizeof(gbk_text));
    Dwg_Entity_SHAPE *shape = dwg_add_SHAPE(hdr, strdup(gbk_text), &ins_pt, scale, obliqueAngle);
    jlong reference = (jlong)(intptr_t)shape;
    jclass shapeClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Shape");
    if (shapeClass == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, shapeClass, "<init>", "(J)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        (*env)->DeleteLocalRef(env, shapeClass);
        return NULL;
    }
    jobject shapeObj = (*env)->NewObject(env, shapeClass, constructor, reference);
    (*env)->DeleteLocalRef(env, clazz);
    (*env)->DeleteLocalRef(env, shapeClass);
    return shapeObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPolyline3d(JNIEnv *env, jobject job, jlong ref, jobject pointList) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || pointList == NULL) {
        return NULL;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint num_points = (*env)->CallIntMethod(env, pointList, sizeMethod);
    if (num_points == 0) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    dwg_point_3d *pnts = malloc(sizeof(dwg_point_3d) * num_points);
    for (int i = 0; i < num_points; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        jdouble z = (*env)->GetDoubleField(env, pointObj, zField);
        pnts[i].x = x;
        pnts[i].y = y;
        pnts[i].z = z;
    }
    Dwg_Entity_POLYLINE_3D *polyline3d = dwg_add_POLYLINE_3D(hdr, num_points, pnts);
    jlong reference = (jlong)(intptr_t)polyline3d;
    jclass polyline3dClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Polyline3d");
    if (polyline3dClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        (*env)->DeleteLocalRef(env, pointClass);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, polyline3dClass, "<init>", "(J)V");
    jobject polyline3dObj = (*env)->NewObject(env, polyline3dClass, constructor, reference);
    (*env)->DeleteLocalRef(env, polyline3dClass);
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, pointClass);
    return polyline3dObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addPolyline2d(JNIEnv *env, jobject job, jlong ref, jobject pointList) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || pointList == NULL) {
        return NULL;
    }
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint num_points = (*env)->CallIntMethod(env, pointList, sizeMethod);
    if (num_points == 0) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point2d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    dwg_point_2d *pnts = malloc(sizeof(dwg_point_2d) * num_points);
    for (int i = 0; i < num_points; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, pointList, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        pnts[i].x = x;
        pnts[i].y = y;
    }
    Dwg_Entity_POLYLINE_2D *polyline2d = dwg_add_POLYLINE_2D(hdr, num_points, pnts);
    jlong reference = (jlong)(intptr_t)polyline2d;
    jclass polyline2dClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Polyline2d");
    if (polyline2dClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        (*env)->DeleteLocalRef(env, pointClass);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, polyline2dClass, "<init>", "(J)V");
    jobject polyline2dObj = (*env)->NewObject(env, polyline2dClass, constructor, reference);
    (*env)->DeleteLocalRef(env, polyline2dClass);
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, pointClass);
    return polyline2dObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addXLine(JNIEnv *env, jobject job, jlong ref, jobject point, jobject vector) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || point == NULL || vector == NULL) {
        return NULL;
    }
    jclass clazz = (*env)->GetObjectClass(env, point);
    if (clazz == NULL) {
        return NULL;
    }
    jfieldID fidX = (*env)->GetFieldID(env, clazz, "x", "D");
    jfieldID fidY = (*env)->GetFieldID(env, clazz, "y", "D");
    jfieldID fidZ = (*env)->GetFieldID(env, clazz, "z", "D");
    jdouble x = (*env)->GetDoubleField(env, point, fidX);
    jdouble y = (*env)->GetDoubleField(env, point, fidY);
    jdouble z = (*env)->GetDoubleField(env, point, fidZ);
    dwg_point_3d pt = {.x = x, .y = y, .z = z};
    jclass vectorClass = (*env)->GetObjectClass(env, vector);
    if (vectorClass == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        return NULL;
    }
    jfieldID vectorXField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID vectorYField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID vectorZField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble vectorX = (*env)->GetDoubleField(env, vector, vectorXField);
    jdouble vectorY = (*env)->GetDoubleField(env, vector, vectorYField);
    jdouble vectorZ = (*env)->GetDoubleField(env, vector, vectorZField);
    dwg_point_3d vec = {.x = vectorX, .y = vectorY, .z = vectorZ};
    Dwg_Entity_XLINE *xline = dwg_add_XLINE(hdr, &pt, &vec);
    jlong reference = (jlong)(intptr_t)xline;
    jclass xlineClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/XLine");
    if (xlineClass == NULL) {
        (*env)->DeleteLocalRef(env, clazz);
        (*env)->DeleteLocalRef(env, vectorClass);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, xlineClass, "<init>", "(J)V");
    jobject xlineObj = (*env)->NewObject(env, xlineClass, constructor, reference);
    (*env)->DeleteLocalRef(env, xlineClass);
    (*env)->DeleteLocalRef(env, clazz);
    (*env)->DeleteLocalRef(env, vectorClass);
    return xlineObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_addSpline(JNIEnv *env, jobject job, jlong ref, jobject fitPoints, jobject begTanVec, jobject endTanVec) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL || fitPoints == NULL) {
        return NULL;
    }
    jclass listClass = (*env)->GetObjectClass(env, fitPoints);
    jmethodID sizeMethod = (*env)->GetMethodID(env, listClass, "size", "()I");
    jint num_points = (*env)->CallIntMethod(env, fitPoints, sizeMethod);
    if (num_points == 0) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jclass pointClass = (*env)->FindClass(env, "io/github/maslke/dwg/common/Point3d");
    if (pointClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        return NULL;
    }
    jmethodID getMethod = (*env)->GetMethodID(env, listClass, "get", "(I)Ljava/lang/Object;");
    jfieldID xField = (*env)->GetFieldID(env, pointClass, "x", "D");
    jfieldID yField = (*env)->GetFieldID(env, pointClass, "y", "D");
    jfieldID zField = (*env)->GetFieldID(env, pointClass, "z", "D");
    dwg_point_3d *pnts = malloc(sizeof(dwg_point_3d) * num_points);
    for (int i = 0; i < num_points; ++i) {
        jobject pointObj = (*env)->CallObjectMethod(env, fitPoints, getMethod, i);
        jdouble x = (*env)->GetDoubleField(env, pointObj, xField);
        jdouble y = (*env)->GetDoubleField(env, pointObj, yField);
        jdouble z = (*env)->GetDoubleField(env, pointObj, zField);
        pnts[i].x = x;
        pnts[i].y = y;
        pnts[i].z = z;
    }
    jclass vectorClass = (*env)->GetObjectClass(env, begTanVec);
    if (vectorClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        (*env)->DeleteLocalRef(env, pointClass);
        return NULL;
    }
    jfieldID vectorXField = (*env)->GetFieldID(env, vectorClass, "x", "D");
    jfieldID vectorYField = (*env)->GetFieldID(env, vectorClass, "y", "D");
    jfieldID vectorZField = (*env)->GetFieldID(env, vectorClass, "z", "D");
    jdouble begTanVecX = (*env)->GetDoubleField(env, begTanVec, vectorXField);
    jdouble begTanVecY = (*env)->GetDoubleField(env, begTanVec, vectorYField);
    jdouble begTanVecZ = (*env)->GetDoubleField(env, begTanVec, vectorZField);
    dwg_point_3d begTanVecPt = {.x = begTanVecX, .y = begTanVecY, .z = begTanVecZ};
    jdouble endTanVecX = (*env)->GetDoubleField(env, endTanVec, vectorXField);
    jdouble endTanVecY = (*env)->GetDoubleField(env, endTanVec, vectorYField);
    jdouble endTanVecZ = (*env)->GetDoubleField(env, endTanVec, vectorZField);
    dwg_point_3d endTanVecPt = {.x = endTanVecX, .y = endTanVecY, .z = endTanVecZ};
    Dwg_Entity_SPLINE *spline = dwg_add_SPLINE(hdr, num_points, pnts,
         &begTanVecPt, &endTanVecPt);
    jlong reference = (jlong)(intptr_t)spline;
    jclass splineClass = (*env)->FindClass(env, "io/github/maslke/dwg/entity/Spline");
    if (splineClass == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        (*env)->DeleteLocalRef(env, pointClass);
        (*env)->DeleteLocalRef(env, vectorClass);
        return NULL;
    }
    jmethodID constructor = (*env)->GetMethodID(env, splineClass, "<init>", "(J)V");
    if (constructor == NULL) {
        (*env)->DeleteLocalRef(env, listClass);
        (*env)->DeleteLocalRef(env, pointClass);
        (*env)->DeleteLocalRef(env, vectorClass);
        (*env)->DeleteLocalRef(env, splineClass);
        return NULL;
    }
    jobject splineObj = (*env)->NewObject(env, splineClass, constructor, reference);
    (*env)->DeleteLocalRef(env, listClass);
    (*env)->DeleteLocalRef(env, pointClass);
    (*env)->DeleteLocalRef(env, vectorClass);
    (*env)->DeleteLocalRef(env, splineClass);
    return splineObj;
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getOwnObjects(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return NULL;
    }
    Dwg_Data *dwg = hdr->parent->dwg;
    if (hdr == NULL) {
        return NULL;
    }

    const char *names = hdr->name;
    Dwg_Object_Ref *object_ref = dwg_find_tablehandle(dwg, names, "BLOCK");
    if (object_ref == NULL) {
        return NULL;
    }

    Dwg_Object *block_obj = object_ref->obj;
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if (listClass == NULL) {
        return NULL;
    }

    jmethodID constructor = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject listObj = (*env)->NewObject(env, listClass, constructor);
    jmethodID addMethod = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");

    Dwg_Object *current_entity = get_first_owned_entity(block_obj);
    while (current_entity != NULL) {
        jobject obj = create_object(env, "io/github/maslke/dwg/obj/DwgObject", (jlong)(intptr_t)current_entity);
        (*env)->CallBooleanMethod(env, listObj, addMethod, obj);
        current_entity = get_next_owned_entity(block_obj, current_entity);
    }
    (*env)->DeleteLocalRef(env, listClass);
    return listObj;
}

JNIEXPORT jstring JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getName(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return NULL;
    }
    const char *chars = hdr->name;
    if (chars == NULL) {
        return NULL;
    }
    char utf_text[200];
    gbk_to_utf8(chars, utf_text, sizeof(utf_text));
    return (*env)->NewStringUTF(env, utf_text);
}

JNIEXPORT void JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_setName(JNIEnv *env, jobject job, jlong ref, jstring name) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return;
    }
    const char *chars = (*env)->GetStringUTFChars(env, name, NULL);
    char utf_text[200];
    utf8_to_gbk(chars, utf_text, sizeof(utf_text));
    hdr->name = strdup(utf_text);
}

JNIEXPORT jobject JNICALL Java_io_github_maslke_dwg_obj_DwgObjectBlockHeader_getParent(JNIEnv *env, jobject job, jlong ref) {
    Dwg_Object_BLOCK_HEADER *hdr = (Dwg_Object_BLOCK_HEADER*)(intptr_t)ref;
    if (hdr == NULL) {
        return NULL;
    }
    if (hdr == NULL) {
        return NULL;
    }
    return create_object(env, "io/github/maslke/dwg/obj/DwgObjectObject", (jlong)(intptr_t)hdr->parent);
}