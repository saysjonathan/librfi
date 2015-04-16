#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "swap.h"

static struct rfi_sizes sz;
static int set = 0;

static int _get_sysinfo(void) {
	int i;
	struct sysinfo si;
	if(set == 0) {
		if((i = sysinfo(&si)) < 0) {
			return i;
		}

		sz.free_b = si.freeswap;
		sz.free_kb = si.freeswap/1024;
		sz.free_mb = si.freeswap/pow(1024,2);
		sz.total_b = si.totalswap;
		sz.total_kb = si.totalswap/1024;
		sz.total_mb = si.totalswap/pow(1024,2);
		sz.used_b = si.totalswap - si.freeswap;
		sz.used_kb = (si.totalswap - si.freeswap)/1024;
		sz.used_mb = (si.totalswap - si.freeswap)/pow(1024,2);
		set = 1;
	}
	return 0;
}

int _get_swap(char **s, int t) {
	int i;
	long l;
	char buf[16];
	if((i = _get_sysinfo()) != 0) {
		return i;
	}
	switch(t) {
		case FREE_B:
			l = sz.free_b;
			break;
		case FREE_KB:
			l = sz.free_kb;
			break;
		case FREE_MB:
			l = sz.free_mb;
			break;
		case TOTAL_B:
			l = sz.total_b;
			break;
		case TOTAL_KB:
			l = sz.total_kb;
			break;
		case TOTAL_MB:
			l = sz.total_mb;
			break;
		case USED_B:
			l = sz.used_b;
			break;
		case USED_KB:
			l = sz.used_kb;
			break;
		case USED_MB:
			l = sz.used_mb;
			break;
	}
	sprintf(buf, "%ld", l);
	strncpy(*s, buf, sizeof(buf));
	return 0;
}
