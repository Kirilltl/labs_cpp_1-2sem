/*Ввести степени и коэффициенты двух многочленов p1(x) и p2(x).
Считать, что все коэффициенты могут принимать значения 0 или 1.
Вычислить и вывести коэффициенты многочленов частного и остатка от деления p1(x) на p2(x).
Все операции выполнять в арифметике по mod 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	int deg1, deg2, deg3;
	int* p1;
	int* p2;
	int* ar_q;
	int tmp = 0;

	printf("Input max deg for p1(x): ");
	scanf("%d", &deg1);
	p1 = (int*)malloc(sizeof(int) * (deg1 + 1));
	input_polynom(p1, deg1);
	modulo_cast(p1, deg1);
	print_polynom(p1, deg1);

	printf("\nInput max deg for p2(x): ");
	scanf("%d", &deg2);
	p2 = (int*)malloc(sizeof(int) * (deg2 + 1));
	input_polynom(p2, deg2);
	modulo_cast(p2, deg2);
	print_polynom(p2, deg2);

	deg3 = deg1 - deg2;
	if (deg3 < 0) {
		ar_q = (int*)malloc(sizeof(int) * (tmp + 1));
		ar_q[0] = 0;
	}
	else {
		ar_q = (int*)malloc(sizeof(int) * (deg3 + 1));
		for (int i = deg3; i >= 0; i--)
			ar_q[i] = 0;
	}

	division_with_remainder(p1, deg1, p2, deg2, ar_q, deg3);

	free(p1);
	free(p2);
	free(ar_q);
	return 0;
}
