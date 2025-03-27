#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_int(const char *str) {
	int sign = 1;
	int ind = 0;
	if (str[0] == '-') {
		sign = -1;
		ind = 1;
	}
	int res = 0;
	int i = ind;
	while (str[i] != '\0') {
		int d = str[i] - '0';
		res *= 10;
		res += d;
		i++;
	}
	res *= sign;
	return res;
}

double str_num(const char *str) {
	double res = 0;
	int ind = 0;
	while (str[ind] != '\0') {
		if ((str[ind] != ' ') && (str[ind] != '+')) {
			int d = str[ind] - '0';
			res *= 10;
			res += d;
		}
		ind++;
	}
	return res;
}
