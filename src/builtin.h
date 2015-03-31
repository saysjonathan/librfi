#ifndef _RFI_BUILTIN_H
#define _RFI_BUILTIN_H
#ifdef __cplusplus
extern "C" {
#endif

#include "rfi_impl.h"

struct builtin builtins[] = {
	{"load_1min", rfi_load_1min},
	{"load_5min", rfi_load_5min},
	{"load_15min", rfi_load_15min},
};

#ifdef __cplusplus
}
#endif
#endif
