#ifndef _RFI_IMPL_H
#define _RFI_IMPL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "rfi.h"

#define MAXNAMELEN 512
#define MAXVALUELEN 512

struct builtin {
	char *name;
	int (*fn) (char **);
};

int rfi_load_1min(char **);
int rfi_load_5min(char **);
int rfi_load_15min(char **);
int rfi_mem_free_bytes(char **);
int rfi_mem_free_kb(char **);
int rfi_mem_free_mb(char **);
int rfi_mem_total_bytes(char **);
int rfi_mem_total_kb(char **);
int rfi_mem_total_mb(char **);
int rfi_mem_used_bytes(char **);
int rfi_mem_used_kb(char **);
int rfi_mem_used_mb(char **);
int rfi_swap_free_bytes(char **);
int rfi_swap_free_kb(char **);
int rfi_swap_free_mb(char **);
int rfi_swap_total_bytes(char **);
int rfi_swap_total_kb(char **);
int rfi_swap_total_mb(char **);
int rfi_swap_used_bytes(char **);
int rfi_swap_used_kb(char **);
int rfi_swap_used_mb(char **);

#ifdef __cplusplus
}
#endif
#endif
