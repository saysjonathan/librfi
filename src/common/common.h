#ifndef _RFI_COMMON_H
#define _RFI_COMMON_H
#ifdef __cplusplus
extern "C" {
#endif

enum _sizes_t {
	FREE_B,
	FREE_KB,
	FREE_MB,
	TOTAL_B,
	TOTAL_KB,
	TOTAL_MB,
	USED_B,
	USED_KB,
	USED_MB,
};

struct rfi_sizes {
	long int free_b;
	long int free_kb;
	long int free_mb;
	long int total_b;
	long int total_kb;
	long int total_mb;
	long int used_b;
	long int used_kb;
	long int used_mb;
};

#ifdef __cplusplus
}
#endif
#endif
