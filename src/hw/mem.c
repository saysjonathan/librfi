#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "../rfi_impl.h"

struct mem {
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

static struct mem m;
int set = 0;

static int _get_sysinfo(void) {
	int i;
	struct sysinfo si;
	if(set == 0) {
		if((i = sysinfo(&si)) < 0) {
			return i;
		}

		m.free_b = si.freeram;
		m.free_kb = si.freeram/1024;
		m.free_mb = si.freeram/pow(1024,2);
		m.total_b = si.totalram;
		m.total_kb = si.totalram/1024;
		m.total_mb = si.totalram/pow(1024,2);
		m.used_b = si.totalram - si.freeram;
		m.used_kb = (si.totalram - si.freeram)/1024;
		m.used_mb = (si.totalram - si.freeram)/pow(1024,2);
		set = 1;
	}
	return 0;
}

static int _mem(char **s, long *l) {
	int i;
	char buf[16];
	if((i = _get_sysinfo()) != 0) {
		return i;
	}
	sprintf(buf, "%ld", *l);
	strncpy(*s, buf, sizeof(buf));
	return 0;
}

int rfi_mem_free_bytes(char **s) {
	return _mem(s, &m.free_b);
}

int rfi_mem_free_kb(char **s) {
	return _mem(s, &m.free_kb);
}

int rfi_mem_free_mb(char **s) {
	return _mem(s, &m.free_mb);
}

int rfi_mem_total_bytes(char **s) {
	return _mem(s, &m.total_b);
}

int rfi_mem_total_kb(char **s) {
	return _mem(s, &m.total_kb);
}

int rfi_mem_total_mb(char **s) {
	return _mem(s, &m.total_mb);
}

int rfi_mem_used_bytes(char **s) {
	return _mem(s, &m.used_b);
}

int rfi_mem_used_kb(char **s) {
	return _mem(s, &m.used_kb);
}

int rfi_mem_used_mb(char **s) {
	return _mem(s, &m.used_mb);
}
