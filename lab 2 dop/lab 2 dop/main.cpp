#include<stdio.h>
#include<stdlib.h>
int comparesl(char* s1, char* s2)
{
	while (1)
	{
		char c1 = *s1;
		char c2 = *s2;
		if (c1 == '\0'  || c2 == '\0')
			return c1 - c2;
		if (c1 != c2)
			return c1 - c2;
		*s1++;
		*s2++;
	}
}
void bubblesort(char* uknaslo[], int che)
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

	//char* uknaslo[100];
	int che = 0;

	// Вычисляем количество слов
	int ignor = 0;
	for (int i = 0;; i++)
	{
		if (mass[i] == '\0')
		{
			break;
		}

		if (isalpha(mass[i]) == 1 && ignor == 0)
		{
			che++;
			ignor = 1;
		}

		if (mass[i] == ' ' || isalpha(mass[i]) == 0)
		{
			ignor = 0;
		}
	}

	// Что имено копировать в дин. память?
	// указатели или сами слова?

/*

	// Выделяем память (она пока пустая)
	printf("che %d\n ", che);
	char** uknaslo = (char**)malloc(che * sizeof(char*));

	for (int i = 0; i < 100; i++)
	{
		printf("<%c> ", mass[i]);
	}

	// помещаем казатели в динамичскую память
	ignor = 0;
	int counter = 0; // для динамич. памяти
	for (int i = 0;; i++)
	{
		if (mass[i] == '\0')
		{
			break;
		}

		if (isalpha(mass[i]) == 1 && ignor == 0)
		{
			uknaslo[counter] = &mass[i];
			ignor = 1;
		}

		if (mass[i] == ' ' || isalpha(mass[i]) == 0)
		{
			ignor = 0;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (mass[i] == ' ' || isalpha(mass[i]) == 0)
		{
			mass[i] = '\0';
		}
	}


	for (int i = 0; i < che; i++)
	{
		printf("%s \n", uknaslo[i]);
	}
*/
	/*

	printf("This is an alphabetical order: \n");
	bubblesort(uknaslo, che);
	for (int i = 0; i < che; i++)
	{
		if (uknaslo[i][0] != '\0')
			printf("%s \n", uknaslo[i]);
	}*/
}

