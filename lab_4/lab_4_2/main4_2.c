#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myReadline.h"
#include "changeLine_2.h"

int main() {
	printf("Введите строку: ");
	char *inputLine = myReadline("");
	while (inputLine != NULL) {
		printf("Введенная строка: \"%s\"\n", inputLine);
		clock_t start = clock();
		char *changedLine = changeLine_2(inputLine);
		clock_t end = clock();
		printf("Новая строка: \"%s\"\n", changedLine);
		double time = (double)(end - start)/CLOCKS_PER_SEC;
		printf("Время выполнения программы: %.10lf \n", time);
		free(inputLine);
		free(changedLine);
		printf("Введите строку: ");
		inputLine = myReadline("");
	}
	return 0;
}

