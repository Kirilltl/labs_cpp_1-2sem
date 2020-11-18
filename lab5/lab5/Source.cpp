#include<stdio.h>
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
	gets_s(mass);

	char word[100];
	gets_s(word);

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
	char* temp = 0;
	for (int i = 0; i < che; i++)
	{
		int len = lengthword(uknaslo[i]);

		if (len > maxlen)
		{
			maxlen = len;
			temp = uknaslo[i];
		}
		
		printf("%s - %d \n", uknaslo[i],lengthword(uknaslo[i]));
	
	}

	printf("%s", temp);

}