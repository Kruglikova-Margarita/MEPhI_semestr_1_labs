#include <stdio.h>
#include <stdlib.h>
#include "checkInput.h"

int init(int **arr, int *len, int *size) {
	printf("=== Инициализация массива === \n");
	printf("Введите длину массива: ");
	int chN = getN(len);
	if (chN == 1) {
		return 1;
	}
	for (int i = 0; i < (*len); i++) {
		if ((i + 1) == (*size)) {
			(*size) *= 2;
			(*arr) = realloc((*arr), (*size) * sizeof(int));
			if (!(*arr)) {
				printf("Ошибка выделения памяти \n");
				return 1;
			}
		}
		int el = 0;
		printf("Введите %d элемент массива: ", i);
		int chZ = getZ(&el);
		if (chZ == 1) {
			return 1;
		}
		(*arr)[i] = el;
	}
	return 0;
}

int insert(int **arr, int *len, int *size, int n, int x) {
	if (n > (*len)) {
		n = (*len);
	}
	(*len)++;
	if ((*len) == (*size)) {
		(*size) *= 2;
		(*arr) = realloc((*arr), (*size) * sizeof(int));
		if (!(*arr)) {
			printf("Ошибка выделения памяти \n");
			return 1;
		}
	}
	for (int i = (*len) - 1; i > (n); i--) {
		(*arr)[i] = (*arr)[i - 1];
	}
	(*arr)[n] = x;
	return 0;
}

int delete(int **arr, int *len, int *size, int n) {
	if ((*len) == 0) {
		printf("Массив пустой. Невозможно удалить элемент \n");
		return -1;
	}
	if (n >= (*len)) {
		printf("Введенный индекс больше длины массива. Невозможно удалить элемент \n");
		return -1;
	}
	for (int i = n; i < *len - 1; i++) {
		(*arr)[i] = (*arr)[i + 1];
	}
	(*len)--;
	if (*len < (*size) / 2) {
		*size /= 2;
		(*arr) = realloc((*arr), (*size) * sizeof(int));
		if (!(*arr)) {
			printf("Ошибка выделения памяти \n");
			return 1;
		}
	}
	return 0;
}

void printArr(int *arr, int len) {
	if (len > 0) {
		for (int i = 0; i < len; i++) {
			printf("arr[%d] = %d \n", i, arr[i]);
		}
	} else {
		printf("пустой \n");
	}
}
