#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <time.h>
#include "changeLine_1.h"

int main() {
	printf("Введите строку: ");
	char *inputLine = readline("");
	while (inputLine != NULL) {
		printf("Введенная строка: \"%s\"\n", inputLine);
		clock_t start = clock();
		char *changedLine = changeLine_1(inputLine);
		clock_t end = clock();
		printf("Новая строка: \"%s\"\n", changedLine);
		double time = (double)(end - start)/CLOCKS_PER_SEC;
		printf("Время выполнения программы: %.10lf \n", time);
		free(inputLine);
		free(changedLine);
		printf("Введите строку: ");
		inputLine = readline("");
	}
	return 0;
}
