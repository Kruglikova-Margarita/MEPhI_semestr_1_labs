#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "user.h"
#include "getOptions.h"
#include "generateData.h"
#include "sorts.h"

int main() {
	int alg = 0;
	int field_way = 0;
	int check = get_option(&alg, &field_way);
	if (check == 1) {
		printf("Некорректный параметр\n");
		return 1;
	}

	int q_el = 0;
	printf("Введите количество элементов в генерируемых массивах: ");
	check = scanf("%d", &q_el);
	if (check != 1) {
		printf("Некорректное значение\n");
		return 1;
	}
	int q_arr = 0;
	printf("Введите количество генерируемых массивов: ");
	check = scanf("%d", &q_arr);
	if (check != 1) {
		printf("Некорректное значение\n");
		return 1;
	}

	int (*compare)(const User*, const User*);
	choose_cmp(field_way, &compare);

	clock_t start;
	clock_t end;

	double time_do = 0;

	srand(time(NULL));
	for (int i = 0; i < q_arr; i++) {
		User *data_rand = generate_data(q_el);

		start = clock();
		switch(alg) {
			case 1:
				qsort(data_rand, q_el, sizeof(User), (int (*)(const void *, const void *)) compare);
				break;
			case 2:
				shaker_sort(data_rand, q_el, compare);
				break;
			case 3:
				insertion_binary(data_rand, q_el, compare);
				break;
		}
		end = clock();

		time_do += (double)(end - start) / CLOCKS_PER_SEC;

		user_free(data_rand, q_el);
		free(data_rand);
	}

	time_do /= q_arr;
	printf("TIME = %lf\n", time_do);

	return 0;
}
