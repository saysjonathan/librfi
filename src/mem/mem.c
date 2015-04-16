#include "mem.h"

int rfi_mem_free_bytes(char **s) {
	return _get_mem(s, FREE_B);
}

int rfi_mem_free_kb(char **s) {
	return _get_mem(s, FREE_KB);
}

int rfi_mem_free_mb(char **s) {
	return _get_mem(s, FREE_MB);
}

int rfi_mem_total_bytes(char **s) {
	return _get_mem(s, TOTAL_B);
}

int rfi_mem_total_kb(char **s) {
	return _get_mem(s, TOTAL_KB);
}

int rfi_mem_total_mb(char **s) {
	return _get_mem(s, TOTAL_MB);
}

int rfi_mem_used_bytes(char **s) {
	return _get_mem(s, USED_B);
}

int rfi_mem_used_kb(char **s) {
	return _get_mem(s, USED_KB);
}

int rfi_mem_used_mb(char **s) {
	return _get_mem(s, USED_MB);
}
