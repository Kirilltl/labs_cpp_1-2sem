#include<stdio.h>
int main()
{
	char mass[] = "hello goodby dog cat car";
	char* uknaslo[100];
	int che=0;

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

	printf("che=%d\n", che);
	
	for(int i=0; i<che; i++)
	{
		printf("%s\n", uknaslo[i]);
	}
}