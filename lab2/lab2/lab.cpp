#include<stdio.h>
int main()
{
	char mass[100]  = "hello goodby dog cat car";


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

	printf("che=%d\n", che);
	
	for (int d = 0; d < che; d++)
	{

		int min = 127; // max value of char
		int minI = 0;
		for (int i = 0; i < che; i++)
		{
			if (*uknaslo[i] < min) 
			{
				minI = i;
				min = *uknaslo[i];
			}
		}


		printf("%s\n", uknaslo[minI]);
		*uknaslo[minI] = 127;
	}
}