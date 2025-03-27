#include <stdio.h>
#include <stdlib.h>
#include "user.h"

User *generate_data(int len);
char *generate_name();

User *generate_data(int len) {
	User *data = (User *) malloc(len * sizeof(User));
	for (int i = 0; i < len; i++) {
		char *name = generate_name();
		char number[17];
		for (int j = 0; j < 16; j++) {
			number[j] = 48 + rand() % 10;
		}
		number[16] = '\0';
		int time = rand();
		data[i] = user_new(name, number, time);
	}

	return data;
}

char *generate_name() {
	char *name = (char *) malloc(1);
	int len_name = 25 + rand() % 11;
	for (int j = 0; j < len_name; j++) {
		name = realloc(name, (j + 1) * sizeof(char));
		if ((j == len_name / 3) || (j == (len_name / 3) * 2)) {
			name[j] = ' ';
		} else {
			name[j] = 97 + rand() % 26;
		}
	}
	name = realloc(name, (len_name + 1) * sizeof(char));
	name[len_name] = '\0';

	return name;
}
