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
int main()
{
	char mass[] = " olleh esaelp evig em a sulp ";
	char* uknaslo[100];
	int che = 0;
	uknaslo[0] = &mass[0];
	che++;
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if (mass[i] == ' ') 
		{
			mass[i] = '\0';
			uknaslo[che] = &mass[i + 1];
			che++;
		}
	}
	printf(" che=%d \n ", che);
	for (int i = 0; i < che; i++)
	{
		printf(" %s \n ", uknaslo[i]);
		if (uknaslo[i][0] != '\0')
		{
			perevorotword(uknaslo[i]);
			printf("\n");
		}
	}
}