#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int lengthword(char* a)
{
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++)
		res++;
	return res;
}
int main()
{
	char mass[100];
	gets(mass);
    char word[100];
	gets(word);
	char* uknaslo[100];
	int che = 0;
	uknaslo[0] = &mass[0];
	che++;
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if ((mass[i] == ' ') || (mass[i] == '.') || (mass[i] == ','))
		{
			mass[i] = '\0';
			uknaslo[che] = &mass[i + 1];
			che++;
		}
	}
	int maxlen = 0;
	char* maxword = 0;
	for (int i = 0; i < che; i++)
	{
		int len = lengthword(uknaslo[i]);

		if (len > maxlen)
		{
			maxlen = len;
			maxword = uknaslo[i];
		}
	}
	for (int i = 0; i < che; i++)
	{
		if (uknaslo[i] != maxword)
			printf("%s ", uknaslo[i]);
		else
			printf("%s ", word);
	}
	printf("\n");
}