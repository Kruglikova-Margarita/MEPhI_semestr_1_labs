#include <stdio.h>
#include <stdlib.h>

void printMenu() {
	printf("Меню команд: \n");
	printf("1 - добавить элемент \n");
	printf("2 - удалить элемент \n");
	printf("3 - вывести текущее состояние массива \n");
	printf("4 - выполнить операцию с массивом \n");
	printf("5 - выйти из программы \n");
}

int readMenu(int *m) {
	int ch = 0;
	printf("Введите команду: ");
	while ((*m != 1) && (*m != 2) && (*m != 3) && (*m != 4) && (*m != 5)) {
		ch = scanf("%d", m);
		if (ch == EOF) {
			return 1;
		}
		if ((*m != 1) && (*m != 2) && (*m != 3) && (*m != 4) && (*m != 5)) {
			printf("Некорректное значение, введите снова: ");
			scanf("%*[^\n]");
		}
	}
	return 0;	
}
