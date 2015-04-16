#ifndef _MEM_IMPL_H
#define _MEM_IMPL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "common/common.h"

int rfi_mem_free_bytes(char **);
int rfi_mem_free_kb(char **);
int rfi_mem_free_mb(char **);
int rfi_mem_total_bytes(char **);
int rfi_mem_total_kb(char **);
int rfi_mem_total_mb(char **);
int rfi_mem_used_bytes(char **);
int rfi_mem_used_kb(char **);
int rfi_mem_used_mb(char **);
int _get_mem(char **s, int t);

#ifdef __cplusplus
}
#endif
#endif
