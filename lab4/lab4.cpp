#include<stdio.h>
int lengthword(char* a) 
{
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++)
		res++;
	return res;
}
void perevorotword(char* b)
{
	for (int i = lengthword(b) - 1; i >= 0; i--)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}
int isalpha(char ch) {
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	printf("Input string:");
	char mass[100];
	gets_s(mass);
	char* uknaslo[100];
	int che = 0;
	uknaslo[0] = &mass[0];
	che++;
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if (isalpha(mass[i]) == 0)
		{
			mass[i] = '\0';
			uknaslo[che] = &mass[i + 1];
			che++;
		}
	}
	for (int i = 0; i < che; i++)
	{
		if (uknaslo[i][0] != '\0') 
		{
			printf("This is an inverted word:");
			perevorotword(uknaslo[i]);
		}
	}
}
