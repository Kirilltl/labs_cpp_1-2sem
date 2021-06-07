#include <stdio.h>
#include <stdlib.h>

void proizvodnaya(int* koef, int* step, int len)
{
	for (int i = 0; i < len; i++)
	{
		koef[i] *= step[i];
		step[i]--;
	}
}
int len_polynoma(int* koef, int* step, int len)
{
	return step[0] + 1;
}
int main() {
	//const int len = 4;

	/*
	int len_a = 4;
	int a[4] = { 2, 6, 3, 4 };
	int len_b = 3;
	int b[3] = { 1, 1, 1 };
	*/
	int len_a = 4;
	int a[4] = { -42, 0,-12, 1 };
	int len_b = 2;
	int b[3] = { -3, 1 };


	int c[4] = { 0,0,0,0 };
	int len_d = 4;
	int d[4] = { 0,0,0,0 };

	//proizvodnaya(a, len);
	//proizvodnaya( b_step, len);

	printf(" ========\n ");

	const int len_c =  len_a - len_b + 1;


	for (int j = len_c - 1, k=0; j>=0; j--, k++)
	{

		c[j] = a[len_a - 1 - k] / b[len_b - 1];
		printf("     c[%d] %d \n ", j, c[j]);

		for (int i = 0; i < len_b; i++)
		{
			d[i + j] = b[i] * c[j];
			printf(" d[%d] %d \n ", i + 1, d[i + 1]);
		}

		for (int i = 0; i < len_a; i++)
		{
			//printf(" a[%d] = a[%d] - d[%d]   %d = %d - %d  \n ", i, i, i, a[i], a[i], d[i]);
			a[i] = a[i] - d[i];
			printf(" a[%d] %d \n ", i, a[i]);
		}

		for (int i = 0; i < len_d; i++)
		{
			d[i] = 0;
		}
		printf(" ========= \n");
	}

	printf(" ===== RESULT ==== \n");
	for (int i = len_c-1; i>=0; i--)
	{
		if(c[i] != 0)
			printf(" %dX^%d ", c[i], i);
	}
	printf("\n");

	printf(" ===== OSTATOK ==== \n");
	for (int i = len_a-1; i >= 0; i--)
	{
		if (a[i] != 0)
			printf(" %dX^%d ", a[i], i);
	}
	printf("\n");

}