#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "myFun.h"
#include "readData.h"

#define str1 "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ -"
#define str2 "1234567890 "
#define str3 "1234567890"

User *read_data(FILE *file, int *len) {
	User *data = NULL;
	char *line = freadline(file);
	int count_str = 1;

	char *field1 = NULL;
	char field2[17];
	int field3 = 0;
	while (line) {
		int checkD = check_data(line, &field1, field2, &field3);
		if (checkD == -1) {
			fprintf(stderr, "Некорректные данные в %d строке файла\n", count_str);
		} else {
			(*len)++;
			data = realloc(data, (*len) * sizeof(User));
			data[(*len) - 1] = user_new(field1, field2, field3);
		}
		free(line);
		line = freadline(file);
		count_str++;
	}
		
	return data;
}

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

int check_data(char *str, char **f1, char f2[17], int *f3) {
	int len_str = strlen(str);
	if (len_str == 0) {
		return -1;
	}
	int sep = count_sym(str, '|');
	if (sep != 2) {
		return -1;
	}
	if ((str[0] == '|') || (str[len_str - 1] == '|')) {
		return -1;
	}
	if (strstr(str, "||") != NULL) {
		return -1;
	}
	
	(*f1) = strtok(str, "|");
	int len1 = strlen(*f1);
	int ch1 = strspn((*f1), str1);
	if ((ch1 < len1) || (count_sym((*f1), ' ') == len1)) {
		return -1;
	}

	char *f = strtok(NULL, "|");
	int len2 = strlen(f);
	if (len2 > 16) {
		return -1;
	}
	int ind = 0;
	while (f[ind] != '\0') {
		f2[ind] = f[ind];
		ind++;
	}
	f2[ind] = '\0';
	if (strspn(f, str3) == 0) {
		if ((*f) == '+') {
			f++;
			len2--;
		} else {
			return -1;
		}
	}
	int ch2 = strspn(f, str2);
	if ((ch2 < len2) || (count_sym(f, ' ') == len2)) {
		return -1;
	}

	f = strtok(NULL, "|");
	(*f3) = str_int(f);
	int len3 = strlen(f);
	if (strspn(f, str3) == 0) {
		if ((*f) == '-') {
			f++;
			len3--;
		} else {
			return -1;
		}
	}
	int ch3 = strspn(f, str3);
	if (ch3 < len3) {
		return -1;
	}
	
	return 0;
}

int count_sym(const char *s, char sym) {
	int len = strlen(s);
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == sym) {
			res++;
		}
	}
	return res;
}
