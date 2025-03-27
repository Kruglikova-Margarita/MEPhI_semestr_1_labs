#include <stdio.h>

int getN(int *n) {
	int ch = scanf("%d", n);
	while (ch != 1) {
		if (ch == EOF) {
			printf("Ошибка!\n");
			return 1;
		} else {
			printf("Некорректное значение. Введите снова: ");
			scanf("%*[^\n]");
			ch = scanf("%d", n);
		}	
	}
	return 0;
}
