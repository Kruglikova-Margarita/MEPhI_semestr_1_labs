#include <stdio.h>
#include <stdlib.h>

int get_option(int *opt1, int *opt23);
void printOpt1();
void printOpt2();
void printOpt3();
int readOpt12(int *n);
int readOpt3(int *n);

int get_option(int *opt1, int *opt23) {
	int opt2 = 0;
	int opt3 = 0;
	
	printOpt1();
	int ch = readOpt12(opt1);
	if (ch == 1) {
		return 1;
	}
	
	printOpt2();
	ch = readOpt12(&opt2);
	if (ch == 1) {
		return 1;
	}

	printOpt3();
	ch = readOpt3(&opt3);
	if (ch == 1) {
		return 1;
	}

	(*opt23) = opt2 * 10 + opt3;

	return 0;
}

void printOpt1() {
	printf("Выберите алгоритм сортировки:\n");
	printf("1 - qsort\n");
	printf("2 - Shaker sort\n");
	printf("3 - Insertion sort with binary search\n");
}

void printOpt2() {
	printf("Выберите поле, по которому осуществляется сортировка:\n");
	printf("1 - ФИО\n");
	printf("2 - номер телефона\n");
	printf("3 - время последнего звонка\n");
}

void printOpt3() {
	printf("Выберите направление сортировки:\n");
	printf("1 - по возрастанию\n");
	printf("2 - по убыванию\n");
}

int readOpt12(int *n) {
	int ch = 0;
	printf("Введите команду: ");
	ch = scanf("%d", n);
	if ((ch == EOF) || ((*n != 1) && (*n != 2) && (*n != 3))) {
		return 1;
	}
	
	return 0;
}

int readOpt3(int *n) {
	int ch = 0;
	printf("Введите команду: ");
	ch = scanf("%d", n);
	if ((ch == EOF) || ((*n != 1) && (*n != 2))) {
		return 1;
	}
	
	return 0;
}
