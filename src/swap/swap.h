#ifndef _SWAP_IMPL_H
#define _SWAP_IMPL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "common/common.h"

int rfi_swap_free_bytes(char **);
int rfi_swap_free_kb(char **);
int rfi_swap_free_mb(char **);
int rfi_swap_total_bytes(char **);
int rfi_swap_total_kb(char **);
int rfi_swap_total_mb(char **);
int rfi_swap_used_bytes(char **);
int rfi_swap_used_kb(char **);
int rfi_swap_used_mb(char **);
int _get_swap(char **s, int t);

#ifdef __cplusplus
}
#endif
#endif
