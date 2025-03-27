#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "changeLine.h"
#include "getN.h"

int main() {
	int N = 0;
	printf("N = ");
	int check = getN(&N);
	if (check == 1) {
		return 1;
	}
	printf("Input line: ");
	char c = getchar();
	c = getchar();
	while (c != EOF) {
		List *line = list_new();
		while (c != '\n') {
			list_add(line, c);
			c = getchar();
		}
		printf("Entered line: ");
		list_print(line);
		change_line(line, N);
		printf("Changed line: ");
		list_print(line);
		list_free(line);
		
		printf("N = ");
		int check = getN(&N);
		if (check == 1) {
			return 1;
		}
		printf("Input line: ");
		c = getchar();
		c = getchar();
	}
	return 0;
}
