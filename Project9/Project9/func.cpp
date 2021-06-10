#include <stdio.h>
#include <stdlib.h>
int proizvodnaya(float* a, float* b, int len_a)
{
	for (int i = len_a - 1; i >= 1; i--)
	{
		b[i - 1] = a[i] * i;
	}
	return len_a - 1;
}
void division(float* a, int len_a)
{
	float* b1 = (float*)malloc(sizeof(float) * len_a); 
	if (b1 == NULL)
	{
		return;
	}
	float* b = (float*)malloc(sizeof(float) * len_a);  
	if (b == NULL)
	{
		return;
	}
	float* c = (float*)malloc(sizeof(float) * len_a);
	if (c == NULL)
	{
		return;
	}
	float* d = (float*)malloc(sizeof(float) * len_a);
	if (d == NULL)
	{
		return;
	}
	for (int i = 0; i < len_a; i++)
	{
		b1[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
	}
	int len_b = 0;
	len_b = proizvodnaya(a, b1, len_a);
	len_b = proizvodnaya(b1, b, len_b);
	int len_d = len_a;
	const int len_c = len_a - len_b + 1;
	for (int j = len_c - 1, k = 0; j >= 0; j--, k++)
	{
		if (b[len_b - 1] != NULL)
			c[j] = a[len_a - 1 - k] / b[len_b - 1];
		else
		{
			printf("ERROR\n");
			return;
		}
		for (int i = 0; i < len_b; i++)
		{
			d[i + j] = b[i] * c[j];
		}
		for (int i = 0; i < len_a; i++)
		{
			a[i] = a[i] - d[i];
		}
		for (int i = 0; i < len_d; i++)
		{
			d[i] = 0;
		}
	}
	printf("QUOTIENT\n");
	bool flag=false;
	for (int i = len_c - 1; i > 0; i--)
	{
		if (c[i] != 0)
		{
			if (i != 0 && c[i] > 0 && flag)
				printf("+");
			flag = true;
			printf("%fX^%d", c[i], i);
		}
	}
	if(c[0]>0 && flag)
		printf("+");
	if (c[0] != 0)
		printf("%f\n",c[0]);
	else
		printf("\n");
	printf("REMAINDER\n");
	flag = false;
	for (int i = len_a - 1; i > 0; i--)
	{
		if (a[i] != 0)
		{
			if (i != 0 && a[i] > 0 && flag)
				printf("+");
			flag = true;
			printf("%fX^%d", a[i], i);
		}
	}
	if (a[0] > 0 && flag)
		printf("+");
	printf("%f\n", a[0]);
	free(b);
	free(b1);
	free(c);
	free(d);
}