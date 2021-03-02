#include<stdio.h>
#include <stdlib.h>
#include "func.h"
int main() {
	double temp;
	int res = scanf("%lf\n", &temp);
	double max = 0.0;
	int index = 0;
	double a = 0;
	double b = 0;
	double c = 0;
	check(a, b, c);
	if (check(a, b, c) == 1)
	{
		printf("Nomer elementa = %d\n", index);
		printf("Max.summa razn = %lf\n", max);
	}
	return 0;
}