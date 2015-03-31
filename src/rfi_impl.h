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

#ifdef __cplusplus
}
#endif
#endif
