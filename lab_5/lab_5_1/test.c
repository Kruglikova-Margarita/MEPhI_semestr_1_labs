#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *freadline(FILE *file) {
	char *ptr = (char *)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do {
		n = fscanf(file, "%80[^\n]", buf);
		if (n < 0) {
			free(ptr);
			ptr = NULL;
			continue;
		} else if (n == 0) {
			fscanf(file, "%*c");
		} else {
			len += strlen(buf);
			ptr = (char *)realloc(ptr, len + 1);
			strcat(ptr, buf);
		}
	} while (n > 0);
	return ptr;
}

int main() {
	FILE *file = fopen("input.txt", "r");
	char *line = freadline(file);
	int i = 1;
	while (line) {
		printf("%d строка файла: %s\n", i, line);
		i++;
		free(line);
		line = freadline(file);
	}
	fclose(file);
	return 0;
}
