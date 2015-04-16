#ifndef _LOAD_IMPL_H
#define _LOAD_IMPL_H
#ifdef __cplusplus
extern "C" {
#endif

int rfi_load_1min(char **);
int rfi_load_5min(char **);
int rfi_load_15min(char **);
int _get_load(char **s, int l);

#ifdef __cplusplus
}
#endif
#endif
