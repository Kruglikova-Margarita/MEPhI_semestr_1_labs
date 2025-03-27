#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "changeLine_1.h"

#define DELIM " \t"

char *changeLine_1(const char *line) {
	char *line1 = strdup(line);
	int len1 = strlen(line1);
	char *line2 = (char *) calloc(len1 * 3, sizeof(char));
	int len2 = 0;
	char *word = strtok(line1, DELIM);
	while (word != NULL) {
		int lenWord = strlen(word);
		int flag = 0;
		int sign = 0;
		if (word[0] == '-') {
			sign = 1;
		}
		for (int i = sign; i < lenWord; i++) {
			if ((word[i] < '0') || (word[i] > '9')) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			memcpy(line2 + len2, word, lenWord * sizeof(char));
			len2 += lenWord;
			line2[len2] = ' ';
			len2++;
		} else {
			int num = number(word, sign);
			if (sign) {
				line2[len2] = '-';
				len2++;
			}
			sprintf(line2 + len2, "%#X ", num);
			int k = 0;
			while (num > 0) {
				k++;
				num /= 16;
			}
			len2 += k + 3;
		}
		word = strtok(NULL, DELIM);
	}
	free(line1);
	if (len2 > 0) {
		--len2;
	}
	if (len2 > 0) {	
		line2[len2] = '\0';
	} else {
		line2 = realloc(line2, sizeof(char));
		line2[0] = '\0';
	}
	line2 = realloc(line2, (len2 + 1) * sizeof(char));
	return line2;
}

int number(const char *w, int s) {
	int k = s;
	int n = 0;
	while(w[k] != '\0') {
		n *= 10;
		n += w[k] - '0';
		k++;
	}
	return n;
}
