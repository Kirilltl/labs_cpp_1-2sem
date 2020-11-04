#include<stdio.h>

int len(char* a) {
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++)
		res++;
	return res;
}

void perevorot(char* b)
{
	for (int i = len(b) - 1; i >= 0; i--)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}



int main()
{
	char mass[] = "does goodby.,. dog., cat car";
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
	printf("che=%d \n", che);


	for (int i = 0; i < che; i++)
	{
		if (uknaslo[i][0] != '\0')
		{
			//printf("%s %d \n", uknaslo[i], len(uknaslo[i]));
			perevorot(uknaslo[i]);
		}
	}
	
}