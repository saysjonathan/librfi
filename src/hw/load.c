#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../rfi_impl.h"

int rfi_load_5min(char **s) {
	int i;
	char buf[4];
	double a[2];
	i = getloadavg(a, 2);
	if(i < 0) {
		return i;
	}
	sprintf(buf, "%0.2f", a[1]);
	strncpy(*s, buf, strlen(buf));
	return 0;
}

int rfi_load_1min(char **s) {
	int i;
	char buf[4];
	double a[1];
	i = getloadavg(a, 1);
	if(i < 0) {
		return i;
	}
	sprintf(buf, "%0.2f", a[0]);
	strncpy(*s, buf, strlen(buf));
	return 0;
}
