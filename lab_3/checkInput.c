#include <stdio.h>
#include <stdlib.h>

int getN(int *n) {
	int ch = 0;
	while ((ch != 1) || ((*n) < 0)) {
		ch = scanf("%d", n);
		if (ch == EOF) {
			return 1;
		}
		if ((ch != 1) || (*n < 0)) {
			printf("Некорректное значение, введите снова: ");
			scanf("%*[^\n]");
		}
	}
	return 0;
}

int getZ(int *z) {
	int ch = 0;
	while (ch != 1) {
		ch = scanf("%d", z);
		if (ch == EOF) {
			return 1;
		}
		if (ch != 1) {
			printf("Некорректное значение, введите снова: ");
			scanf("%*[^\n]");
		}
	}
	return 0;
}

int getFin(int *f) {
	int ch = 0;
	while ((ch != 1) || (((*f) != 0) && ((*f) != 1))) {
		ch = scanf("%d", f);
		if (ch == EOF) {
			return 1;
		}
		if ((ch != 1) || (((*f) != 0) && ((*f) != 1))) {
			printf("Некорректное значение, введите снова: ");
			scanf("%*[^\n]");
		}
	}
	return 0;
}
