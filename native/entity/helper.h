#include <jni.h>
#include <dwg_api.h>

#ifndef DWG_LIB_HELPER_H
#define DWG_LIB_HELPER_H
#ifdef __cplusplus
extern "C" {
#endif

BITCODE_RC dxf_find_lweight(const int);
int utf8_to_gbk(const char *, char *, size_t);
#ifdef __cplusplus
}
#endif
#endif
