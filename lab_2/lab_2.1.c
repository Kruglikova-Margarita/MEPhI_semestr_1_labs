#include <stdio.h>
#include <math.h>

float ap_ar(float arg, int ac) {
	float sum = 0;
	float el = 0;
	float sq = arg * arg;
	float den = 1;
	float num = arg;
	for (int i = 0; i <= ac; i++) {
		el = num / den;
		sum += el;
		den += 2;
		num *= sq;
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

int input_n(int *k) {
	int t_i = 0;
	while ((t_i != 1) || (*k <= 0)) {
		printf("Введите количество членов ряда: ");
		t_i = scanf("%d", k);
		if (t_i == EOF) {
			return 1;
		}
		if ((t_i != 1) || (*k <= 0)) {
			printf("Введенное значение некорректно \n");
			scanf("%*[^\n]");
		}
	}
	return 0;
}

int main() {
	float x = 0;
	int n = 0;	
	int ch_x = input_x(&x);
	if (ch_x == 1) {
		return 1;
	}
	int ch_n = input_n(&n);
	if (ch_n == 1) {
		return 1;
	}

	float ap_ar_x = ap_ar(x, n);
	float ar_x = ar(x);

	printf("Приближенный ареатенгенс: %f\n", ap_ar_x);
	printf("Точный ареатангенс: %f\n", ar_x);
	return 0;
}

