#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "user.h"
#include "getOptions.h"
#include "readData.h"
#include "sorts.h"
#include "writeData.h"

int check_format();

int main() {
	int alg = 0;
	int field_way = 0;
	int check_opt = get_option(&alg, &field_way);
	if (check_opt == 1) {
		printf("Некорректный параметр\n");
		return 1;
	}

	char *name_input = readline("Введите имя входного текстового файла: ");
	int check_f = check_format(name_input);
	if (check_f == -1) {
		printf("Некорректный формат файла\n");
		free(name_input);
		return -1;
	}
	FILE *file_input = fopen(name_input, "r");
	if (file_input == NULL) {
		printf("Файл не найден\n");
		free(name_input);
		return -1;
	}

	char *name_output = readline("Введите имя выходного текстового файла: ");
	check_f = check_format(name_output);
	if (check_f == -1) {
		printf("Некорректный формат файла\n");
		free(name_input);
		free(name_output);
		return -1;
	}
	FILE *file_output = fopen(name_output, "w");
	if (file_output == NULL) {
		printf("Файл не найден\n");
		free(name_input);
		free(name_output);
		return -1;
	}
	
	int len_data = 0;
	User *data_user = read_data(file_input, &len_data);
	if (len_data == 0) {
		printf("Массив данных пустой, так как в файле отсутствуют корректные данные\n");
		free(name_input);
		fclose(file_input);
		user_free(data_user, len_data);
		free(data_user);
		return 1;
	}

	int (*compare)(const User*, const User*);
	choose_cmp(field_way, &compare);

	switch(alg) {
		case 1:
			qsort(data_user, len_data, sizeof(User), (int (*)(const void *, const void *)) compare);
			break;
		case 2:
			shaker_sort(data_user, len_data, compare);
			break;
		case 3:
			insertion_binary(data_user, len_data, compare);
			break;
	}

	write_data(file_output, data_user, len_data);
	
	free(name_input);
	fclose(file_input);
	free(name_output);
	fclose(file_output);
	user_free(data_user, len_data);
	free(data_user);
	return 0;
}



int check_format(const char *name) {
	int len = strlen(name);
	if (len <= 4) return -1;
	if ((name[len - 4] != '.') || (name[len - 3] != 't') || (name[len - 2] != 'x') || (name[len - 1] != 't')) return -1;

	return 0;
}
