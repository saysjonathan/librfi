#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../rfi_impl.h"

static int _get_load(char **s, int l) {
	int i;
	char buf[4];
	double a[3];
	i = getloadavg(a, 3);
	if(i < 0) {
		return i;
	}
	sprintf(buf, "%0.2f", a[l]);
	strncpy(*s, buf, strlen(buf));
	return 0;
}

int rfi_load_1min(char **s) {
	return _get_load(s, 1);
}

int rfi_load_5min(char **s) {
	return _get_load(s, 2);
}

int rfi_load_15min(char **s) {
	return _get_load(s, 3);
}
