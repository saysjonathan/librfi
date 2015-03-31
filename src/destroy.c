#include <stdlib.h>
#include "rfi_impl.h"

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
