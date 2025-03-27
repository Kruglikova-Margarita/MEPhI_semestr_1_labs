#include <stdio.h>
#include <stdlib.h>
#include "arrayLib.h"

int task(int **data1, int *l1, int *s1, int **data2, int *l2, int *s2) {
	for (int i = (*l1) - 1; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < (*l1); j++) {
			if ((i != j) && ((*data1)[i] == (*data1)[j])) {
				flag = 1;
			}
		}
		if (flag == 0) {
			(*l2)++;
			if ((*l2) == (*s2)) {
				(*s2) *= 2;
				(*data2) = realloc((*data2), (*s2) * sizeof(int));
				if (!(*data2)) {
					printf("Ошибка выделения памяти \n");
					return 1;
				}
			}
			for (int i = (*l2) - 1; i > 0; i--) {
				(*data2)[i] = (*data2)[i - 1];
			}
			(*data2)[0] = (*data1)[i];
			int chDel = delete(data1, l1, s1, i);
			if (chDel == 1) {
				return 1;
			}
		}
	}
	return 0;
}
