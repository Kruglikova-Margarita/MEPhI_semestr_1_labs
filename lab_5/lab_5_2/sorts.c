#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void choose_cmp(int opt, int (**fun)(const User*, const User*)) {
	switch(opt) {
		case 11:
			(*fun) = user_cmp_name_incr;
			break;
		case 12:
			(*fun) = user_cmp_name_decr;
			break;
		case 21:
			(*fun) = user_cmp_number_incr;
			break;
		case 22:
			(*fun) = user_cmp_number_decr;
			break;
		case 31:
			(*fun) = user_cmp_time_incr;
			break;
		case 32:
			(*fun) = user_cmp_time_decr;
			break;
	}
}

void swap(User *u1, User *u2) {
	User tmp = *u1;
	*u1 = *u2;
	*u2 = tmp;
}

void shaker_sort(User *data, int len, int (*cmp_fun)(const User*, const User*)) {
	int cmp;
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		for (int i = left; i < right; i++) {
			cmp = cmp_fun((data + i), (data + i + 1));
			if (cmp > 0) swap((data + i), (data + i + 1));
		}
		right--;
		for (int i = right; i > left; i--) {
			cmp = cmp_fun((data + i), (data + i - 1));
			if (cmp < 0) swap((data + i), (data + i - 1));
		}
		left++;
	}
}

void insertion_binary(User *data, int len, int (*cmp_fun)(const User*, const User*)) {
	int cmp;
	for (int i = 1; i < len; i++) {
		User buf = data[i];
		int left = 0;
		int right = i - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			cmp = cmp_fun(&buf, (data + middle));
			if (cmp < 0) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		for (int j = i; j > left; j--) {
			data[j] = data[j - 1];
		}
		data[left] = buf;
	}
}
