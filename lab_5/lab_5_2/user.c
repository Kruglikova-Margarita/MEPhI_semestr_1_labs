#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "myFun.h"

User user_new(char *name, char number[17], int time) {
 	User u;
 	u.name = name;
 	for (int i = 0; i < 17; i++) {
 		u.number[i] = number[i];
 	}
 	u.time = time;
	return u;
}

void user_print(const User *u) {
	printf("{%s, %s, %d}", u->name, u->number, u->time);
}

void user_array_print(const User *arr, int len) {
 	for (int i = 0; i < len; i++) {
 		printf("a[%d] = ", i);
 		user_print(arr + i);
		printf("\n");
	}
}

void user_free(User *arr, int len) {
	for (int i = 0; i < len; i++) {
		free(arr[i].name);
	}
}


int user_cmp_name_incr(const User *u1, const User *u2) {
	return strcmp(u1->name, u2->name);
}
int user_cmp_name_decr(const User *u1, const User *u2) {
	return strcmp(u2->name, u1->name);
}

int user_cmp_number_incr(const User *u1, const User *u2) {
	double num1 = str_num(u1->number);
	double num2 = str_num(u2->number);
	if (num1 > num2) return 1;
	else if (num1 == num2) return 0;
	else return -1;
}
int user_cmp_number_decr(const User *u1, const User *u2) {
	double num1 = str_num(u1->number);
	double num2 = str_num(u2->number);
	if (num1 > num2) return -1;
	else if (num1 == num2) return 0;
	else return 1;
}

int user_cmp_time_incr(const User *u1, const User *u2) {
	return u1->time - u2->time;
}
int user_cmp_time_decr(const User *u1, const User *u2) {
  	return u2->time - u1->time;
}
