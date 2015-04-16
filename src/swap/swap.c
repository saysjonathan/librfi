#include "swap.h"

int rfi_swap_free_bytes(char **s) {
	return _get_swap(s, FREE_B);
}

int rfi_swap_free_kb(char **s) {
	return _get_swap(s, FREE_KB);
}

int rfi_swap_free_mb(char **s) {
	return _get_swap(s, FREE_MB);
}

int rfi_swap_total_bytes(char **s) {
	return _get_swap(s, TOTAL_B);
}

int rfi_swap_total_kb(char **s) {
	return _get_swap(s, TOTAL_KB);
}

int rfi_swap_total_mb(char **s) {
	return _get_swap(s, TOTAL_MB);
}

int rfi_swap_used_bytes(char **s) {
	return _get_swap(s, USED_B);
}

int rfi_swap_used_kb(char **s) {
	return _get_swap(s, USED_KB);
}

int rfi_swap_used_mb(char **s) {
	return _get_swap(s, USED_MB);
}
