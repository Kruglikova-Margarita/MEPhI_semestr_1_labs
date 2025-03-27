#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

size_t myStrlen(const char *str) {
	int res = 0;
	while (str[res] != '\0') {
		res ++;
	}
	return res;
}

char *myStrdup(const char *str) {
	int len = myStrlen(str);
	char *res = (char *) malloc((len + 1) *sizeof(char));
	myMemcpy(res, str, len *sizeof(char));
	res[len] = '\0';
	return res;
}

void *myMemcpy(void *dest, const void *s, size_t size) {
	int n = size / sizeof(char);
	char *dest1 = (char *) dest;
	char *s1 = (char *) s;
	for (int i = 0; i < n; i++) {
		dest1[i] = s1[i];
	}
	return dest;
}

char *myStrcat(char *dest, const char *app) {
	char *ptr = dest + myStrlen(dest);
	int i = 0;
	while (app[i] != '\0') {
		ptr[i] = app[i];
		i++;
	}
	ptr[i] = '\0';
	return dest;
}

int flagSep(const char c, const char *s) {
	int len = myStrlen(s);
	if (c == '\0'){
		return -1;
	}
	for (int i = 0; i < len; i++) {
		if (c == s[i]) {
			return 1;
		}
	}
	return 0;
}

char *myStrtok(char *str, const char *sep) {
	static char *next;
	char *w = NULL;
	int lenW = 0;
	if (str != NULL) {
		next = str;
	}
	if (next == NULL) {
		return w;
	}
	int flagS = flagSep(next[0], sep);
	if (flagS == -1) {
		return w;
	}
	while (flagS == 1) {
		flagS = flagSep(next[0], sep);
		if (flagS == 1) {
			next++;
		}
	}
	if (flagS == -1) {
		return w;
	}
	while (flagS == 0) {
		flagS = flagSep(next[0], sep);
		if (flagS == 0) {
			lenW++;
			w = realloc(w, lenW * sizeof(char));
			w[lenW - 1] = next[0];
			next++;
		}
	}
	w = realloc(w, (lenW + 1) * sizeof(char));
	w[lenW] = '\0';
	return w;
}
