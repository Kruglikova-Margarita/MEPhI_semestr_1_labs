#include <stdio.h>
#include <stdlib.h>
#include "myString.h"
#include "changeLine_2.h"

#define DELIM " \t"

char *changeLine_2(const char *line) {
	char *line1 = myStrdup(line);
	int len1 = myStrlen(line1);
	char *line2 = (char *) calloc(len1 * 3, sizeof(char));
	int len2 = 0;
	char *word = myStrtok(line1, DELIM);
	while (word != NULL) {
		int lenWord = myStrlen(word);
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
			myMemcpy(line2 + len2, word, lenWord * sizeof(char));
			len2 += lenWord;
			line2[len2] = ' ';
			len2++;
		} else {
			int num = number(word, sign);
			sixteen(num, sign, &line2, &len2);
			line2[len2] = ' ';
			len2++;
		}
		free(word);
		word = myStrtok(NULL, DELIM);
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

void sixteen(int n, int s, char **str, int *len) {
	(*len) += (s + 2);
	int start = (*len);
	if (s == 1) {
		(*str)[(*len) - s - 2] = '-';
	}
	(*str)[(*len) - 2] = '0';
	(*str)[(*len) - 1] = 'x';
	while (n != 0) {
		(*len)++;
		for (int i = (*len) - 1; i > start; i--) {
			(*str)[i] = (*str)[i - 1];
		}
		int f = n % 16;
		if (f < 10) {
			(*str)[start] = '0' + f;
		} else {
			(*str)[start] = 'A' + f - 10;
		}
		n /= 16;
	}
}

