#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void write_data(FILE *file, User *data, int len) {
	for (int i = 0; i < len; i++) {
		fprintf(file, "%s|%s|%d\n", data[i].name, data[i].number, data[i].time);
	}
}
