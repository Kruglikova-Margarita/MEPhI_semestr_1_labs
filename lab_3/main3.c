#include <stdio.h>
#include <stdlib.h>
#include "checkInput.h"
#include "arrayLib.h"
#include "menu.h"
#include "task.h"

int main() {
	int ind = 0;
	int el = 0;
	int len1 = 0;
	int len2 = 0;
	int size1 = 1;
	int size2 = 1;
	int *arr1 = malloc(sizeof(int));
	int *arr2 = malloc(sizeof(int));
	int chInit = init(&arr1, &len1, &size1);
	if (chInit == 1) {
		free(arr1);
		free(arr2);
		return 1;
	}
	printMenu();
	int menu = 0;
	int chM = readMenu(&menu);
	if (chM == 1) {
		free(arr1);
		free(arr2);
		return 1;
	}
	while (menu != 5) {
		switch(menu) {
			case 1:
				printf("=== Добавление элемента по индексу === \n");
				printf("Введите индекс: ");
				int chN = getN(&ind);
				if (chN == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				printf("Введите элемент: ");
				int chZ = getZ(&el);
				if (chZ == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				int chIns = insert(&arr1, &len1, &size1, ind, el);
				if (chIns == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				break;
			case 2:
				printf("=== Удаление элемента по индексу === \n");
				chN = getN(&ind);
				if (chN == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				int chDel = delete(&arr1, &len1, &size1, ind);
				if (chDel == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				break;
			case 3:
				printf("=== Вывод текущего состояния массива === \n");
				printf("Введенный массив: \n");
				printArr(arr1, len1);
				break;
			case 4:
				printf("=== Выполнение операции с массивом === \n");
				int chT = task(&arr1, &len1, &size1, &arr2, &len2, &size2);
				if (chT == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				printf("Введенный массив: \n");
				printArr(arr1, len1);
				printf("Новый массив: \n");
				printArr(arr2, len2);
				printf("Завершить программу? 1 - да, 0 - нет \n");
				printf("> ");
				int fin = 0;
				int chFin = getFin(&fin);
				if (chFin == 1) {
					free(arr1);
					free(arr2);
					return 1;
				}
				if (fin == 1) {
					free(arr1);
					free(arr2);
					return 0;
				} else {
					arr2 = realloc(arr2, sizeof(int));
					len2 = 0;
					size2 = 1;
				}
				break;
		}
		menu = 0;
		chM = readMenu(&menu);
		if (chM == 1) {
			free(arr1);
			free(arr2);
			return 1;
		}
	}
	free(arr1);
	free(arr2);
	return 0;
}
