#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main() 
{
	int len_a = 0;
	int degr = 0;
	int counter = 0;
	printf("Input a degree\n");
	int r = scanf("%d", &degr);
	len_a = degr + 1;
	float* a = (float*)malloc(sizeof(float) * len_a);
	if (a == NULL)
	{
		exit(1);
	}
	for (int i = 0; i < len_a; i++)
	{
		printf("Input coef[%d]\n", i);
		int t = scanf("%f", &a[i]);
		if (t == NULL)
			exit(1);
	}
	division(a, len_a);
	free(a);
}