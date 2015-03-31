#ifndef _RFI_BUILTIN_H
#define _RFI_BUILTIN_H
#ifdef __cplusplus
extern "C" {
#endif

#include "rfi_impl.h"

struct builtin builtins[] = {
	{"load_1min",          rfi_load_1min},
	{"load_5min",          rfi_load_5min},
	{"load_15min",         rfi_load_15min},
	{"memory_free_bytes",  rfi_mem_free_bytes},
	{"memory_free_kb",     rfi_mem_free_kb},
	{"memory_free_mb",     rfi_mem_free_mb},
	{"memory_total_bytes", rfi_mem_total_bytes},
	{"memory_total_kb",    rfi_mem_total_kb},
	{"memory_total_mb",    rfi_mem_total_mb},
	{"memory_used_bytes",  rfi_mem_used_bytes},
	{"memory_used_kb",     rfi_mem_used_kb},
	{"memory_used_mb",     rfi_mem_used_mb},
	{"swap_free_bytes",    rfi_swap_free_bytes},
	{"swap_free_kb",       rfi_swap_free_kb},
	{"swap_free_mb",       rfi_swap_free_mb},
	{"swap_total_bytes",   rfi_swap_total_bytes},
	{"swap_total_kb",      rfi_swap_total_kb},
	{"swap_total_mb",      rfi_swap_total_mb},
	{"swap_used_bytes",    rfi_swap_used_bytes},
	{"swap_used_kb",       rfi_swap_used_kb},
	{"swap_used_mb",       rfi_swap_used_mb},
};

#ifdef __cplusplus
}
#endif
#endif
