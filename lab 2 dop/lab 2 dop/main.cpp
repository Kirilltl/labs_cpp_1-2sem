#include<stdio.h>
#include <stdlib.h>
#include<string.h>


int comparesl(const char* str1, const char* str2)
{
	const char* s1 = (const char*)str1;
	const char* s2 = (const char*)str2;

	 char c1 = (char)*s1;
	 char c2 = (char)*s2;

	while (c1 == c2)
	{

		if (c1 == '\0') // есди достигнут конец слова
			return c1 - c2;

		*s1++;
		*s2++;

		c1 = (char)*s1;
		c2 = (char)*s2;
	}
	return c1 - c2;
}

int alfasort(const void* slovo1, const void* slovo2) // compare two objects
{
	//return strcmp(*(char**)slovo1, *(char**)slovo2); // compare two strings: return 0,1,-1 
	return comparesl(*(char**)slovo1, *(char**)slovo2);

	// char** - это указатель на char*
	// *slovo1 - это значение этого указателя на char*

}


int main()
{
	char mass[100] = "hello goodby dog cat car";


	char* uknaslo[100]; // ykazatel on single words 
	int che = 0;// number of words

	uknaslo[0] = &mass[0];
	che++;
	for (int i = 0; mass[i] != '\0'; i++)// simvol konza stroki
	{
		if (mass[i] == ' ')
		{
			mass[i] = '\0';// razdel'aem stroky na otdeln slova
			uknaslo[che] = &mass[i + 1];
			che++;
		}
	}



	printf("che=%d\n", che);

	qsort(uknaslo, che, sizeof(char*), alfasort);


	for (int i = 0; i < che; i++)
		printf("%s\n", uknaslo[i]);
		
}