#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "builtin.h"

int rfi_get_one(char *name, rfi *r) {
	int i, s;
	errno = 0;
	if((r->name = malloc(MAXNAMELEN)) == NULL) {
		return errno;
	}
	if((r->value = malloc(MAXVALUELEN)) == NULL) {
		return errno;
	}
	s = sizeof(builtins)/sizeof(struct rfi);
	for(i = 0; i < s; i++) {
		if(strcmp(builtins[i].name, name) == 0) {
			strncpy(r->name, name, strlen(name));
			i = builtins[i].fn(&r->value);
			return i;
		}
	}
	return 1;
}

int rfi_get_all(rfi *a[]) {
	int i, s;
	s = sizeof(builtins)/sizeof(struct rfi);
	for(i = 0; i < s; i++) {
		a[i] = malloc(sizeof(struct rfi));
		if((a[i]->name = malloc(MAXNAMELEN)) == NULL) {
			return errno;
		}
		if((a[i]->value = malloc(MAXVALUELEN)) == NULL) {
			return errno;
		}
		strncpy(a[i]->name, builtins[i].name, strlen(builtins[i].name));
		builtins[i].fn(&a[i]->value);
	}
	a[s] = NULL;
	return 0;
}

void rfi_destroy_one(rfi *r) {
	free(r->value);
	free(r->name);
}

void rfi_destroy_all(rfi *a[]) {
	int i;
	for(i = 0; a[i] != NULL; i++) {
		free(a[i]->value);
		free(a[i]->name);
		free(a[i]);
	}
}
