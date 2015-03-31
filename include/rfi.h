#ifndef _RFI_H
#define _RFI_H
#ifdef __cplusplus
extern "C" {
#endif

#define RFIBUILTINLEN 512

typedef struct rfi rfi;
struct rfi {
	char *name;
	char *value;
};

int rfi_get_one(char *name, rfi *);
int rfi_get_all(rfi *[]);
void rfi_destroy_one(rfi *);
void rfi_destroy_all(rfi *[]);

#ifdef __cplusplus
}
#endif
#endif
