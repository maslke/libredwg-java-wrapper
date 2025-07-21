#include <jni.h>
#include <dwg_api.h>

#ifndef DWG_LIB_HELPER_H
#define DWG_LIB_HELPER_H
#ifdef __cplusplus
extern "C" {
#endif

BITCODE_RC dxf_find_lweight(const int);
int find_linewt_by_index(const int);
int utf8_to_gbk(const char *, char *, size_t);
int gbk_to_utf8(const char *, char *, size_t);
jobject createDwgObjectRef(JNIEnv *, Dwg_Object_Ref *);
jobject createDwgColor(JNIEnv *, Dwg_Color *);
void log_info(JNIEnv *, const char*);
#ifdef __cplusplus
}
#endif
#endif
