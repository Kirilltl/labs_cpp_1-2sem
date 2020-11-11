#include<stdio.h>
int comparesl(char* s1, char* s2)  
{
	while (1)
		{
			char c1 = *s1;     
			char c2 = *s2;     
				if (c1 == '\0')    
					return c1 - c2;
				if (c1 != c2)      
					return c1 - c2;
		    *s1++;             
		    *s2++;             
		}
}
void qsort(char* uknaslo[], int che)
{
	for (int j = 0; j < (che - 1); j++)
	{
		for (int i = 0; i < (che - 1); i++)
		{
			int result = comparesl(uknaslo[i], uknaslo[i + 1]); 
			char* temp;
			if (result > 0) 
			{
				temp = uknaslo[i];
				uknaslo[i] = uknaslo[i + 1];
				uknaslo[i + 1] = temp;
			}
		}
	}
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
qsort(uknaslo, che);
	for (int i = 0; i < che; i++)
	{
		if (uknaslo[i][0] != '\0')
		printf("%s \n", uknaslo[i]);
	}
}
