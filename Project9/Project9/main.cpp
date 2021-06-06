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
	const int len = 4;
	int k[4] = { 8, 2, 10, 5 };
	int s[4] = { 3, 2, 1, 0 };
	int* a_koef = (int*)malloc(sizeof(int) * len);
	int* a_step = (int*)malloc(sizeof(int) * len);
	int* b_koef = (int*)malloc(sizeof(int) * len);
	int* b_step = (int*)malloc(sizeof(int) * len);
	int* c_koef = (int*)malloc(sizeof(int) * len);
	int* c_step = (int*)malloc(sizeof(int) * len);
	int* d_koef = (int*)malloc(sizeof(int) * len);
	int* d_step = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
	{
		a_koef[i] = k[i];
		a_step[i] = s[i];
		b_koef[i] = k[i];
		b_step[i] = s[i];
	}
	proizvodnaya(b_koef, b_step, len);
	proizvodnaya(b_koef, b_step, len);
	for (int i = 0; i < len; i++)
	{
		printf(" %d\n ", b_koef[i]);
	}
	for (int i = 0; i < len; i++)
	{
		printf(" %d\n ", b_step[i]);
	}
	printf(" ========\n ");
	for (int i = 0; i < len; i++)
	{
		printf(" %d\n ", a_koef[i]);
	}
	for (int i = 0; i < len; i++)
	{
		printf(" %d\n ", a_step[i]);
	}
	c_koef[0] = a_koef[0] / b_koef[0];
	c_step[0] = a_step[0] - b_step[0];

	//for(int i=0; i<)


}