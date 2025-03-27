#include <stdio.h>
#include <math.h>

float ap_ar(float arg, float ac, int *k) {
	float sum = arg;
	float el = arg;
	float sq = arg * arg;
	float den = 1;
	float num = arg;
	while (fabs(el) > ac) {
		num *= sq;
		den += 2;
		el = num / den;
		sum += el;
		*k += 1;
	}
	return sum;
}

float ar(float arg) {
	float ln = log((sqrt(1 - arg * arg)) / (1 - arg));
	return ln;
}

int input_x(float *arg) {
	int t_f = 0;
	while ((t_f != 1) || (*arg <= -1) || (*arg >= 1)) {
		printf("Введите x (|x| < 1): ");
		t_f = scanf("%f", arg);
		if (t_f == EOF) {
			return 1;
		}
		if ((t_f != 1) || (*arg <= -1) || (*arg >= 1)) {
			printf("Введенное значение некорректно \n");
			scanf("%*[^\n]");
		}
	}
	return 0;
}

int input_E(float *ac) {
	int t_f = 0;
	while ((t_f != 1) || (*ac <= 0)) {
		printf("Введите точность: ");
		t_f = scanf("%f", ac);
		if (t_f == EOF) {
			return 1;
		}
		if ((t_f == 0) || (*ac <= 0)) {
			printf("Введенное значение некорректно \n");
			scanf("%*[^\n]");
		}
	}
	return 0;
}

int main() {
	int q = 1;
	float x = 0;
	float E = 0;
	int ch_x = input_x(&x);
	if (ch_x == 1) {
		return 1;
	}
	int ch_E = input_E(&E);
	if (ch_E == 1) {
		return 1;
	}

	float ap_ar_x = ap_ar(x, E, &q);
	float ar_x = ar(x);

	printf("Приближенный ареатангенс: %f\n", ap_ar_x);
	printf("Точный ареатангенс: %f\n", ar_x);
	printf("Количество элементов ряда: %d\n", q);
	return 0;
}
