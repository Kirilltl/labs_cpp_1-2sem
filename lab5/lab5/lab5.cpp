#include<stdio.h>
int lengthword(char* a)
{
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++)
		res++;
	return res;
}
