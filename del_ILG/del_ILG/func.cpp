#include <stdio.h>
void input_polynom(int* arr, int size)
{
	int c;
	for (int i = size; i >= 0; i--)
	{
		scanf("%d", &c);
		arr[i] = c;
	}
	printf("Polynom: ");
}

void modulo_cast(int* arr, int size)
{
	int a = 0;
	for (int i = size; i >= 0; i--)
	{
		arr[i] = arr[i] % 2;
		if (arr[i] == -1)
			arr[i] = 1;
	}
}

void print_polynom(int* arr, int size)
{
	for (int i = size; i > 0; i--)
	{
		if (arr[i] == 1)
			printf("%dx^%d+", arr[i], i);
	}
	printf("%d\n", arr[0]);
}

void division_with_remainder(int* p1, int size1, int* p2, int size2, int* ar_q, int size3)
{
	for (int k = size3; k >= 0; k--)
	{
		ar_q[k] = p1[k + size2] / p2[size2];
		p1[size1--] = 0;
		modulo_cast(ar_q, size3);

		for (int j = (size2 + k - 1); j >= k; j--)
		{
			p1[j] = p1[j] - ar_q[k] * p2[j - k];
		}
		modulo_cast(p1, size1);
	}

	printf("\n\nChasnoe: ");
	for (int i = size3; i > 0; i--)
	{
		if (ar_q[i] != 0)
			printf("%dx^%d+", ar_q[i], i);
	}
	printf("%d", ar_q[0]);

	printf("\n\nOstatok: ");
	for (int i = size1; i > 0; i--)
	{
		if (p1[i] != 0)
			printf("%dx^%d+", p1[i], i);
	}
	printf("%d\n", p1[0]);
}