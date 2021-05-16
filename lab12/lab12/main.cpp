#include <stdio.h>
#include "fVector.h"
/*Создайте класс с именем fVector для выполнения действий с векторами типа float длиной не больше 100. Длина вектора должна задаваться в конструкторе.*/
int main() {
	printf("Addition:\n");
	fVector a1(3);
	a1.input();
	fVector b1(3);
	b1.input();
	(fVector() = a1 + b1).output();

	printf("Subtraction:\n");
	fVector a2(4);
	a2.input();
	fVector b2(4);
	b2.input();
	fVector c2(4);
	c2.input();
	(fVector() = a2 - b2 - c2).output();

	printf("Multiplication:\n");
	fVector a3(3);
	a3.input();
	float a = 0;
	printf("Enter a multiplier:\n");
	scanf("%f", &a);
	(fVector() = a3 * a).output();

	printf("Division:\n");
	fVector a4(3);
	a4.input();
	float b = 0;
	printf("Enter a divisor:\n");
	scanf("%f", &b);
	(fVector() = a4 / b).output();

	printf("Scalar:\n");
	fVector a5(4);
	a5.input();
	fVector b5(4);
	b5.input();
	printf("Scalar = %f\n", a5 ^ b5);

	int error = 0;
	printf("%f\n", a5.get(1, error));
	if (error != 0) {
		printf("INVALID INDEX!\n");
		return 1;
	}
	a5.set(1, 2.8, error);
	if (error != 0) {
		printf("INVALID INDEX!\n");
		return 1;
	}
	printf("%f\n", a5.get(1, error));
	if (error != 0) {
		printf("INVALID INDEX!\n");
		return 1;
	}

}