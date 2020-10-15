#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int comparesl(char* s1, char* s2)  // s1 ukaz na 1-u bukv v 1-m slov;s2 ukaz na 1-u bukv vo 2-m slov
{
	while (1)               // beskonech cikl
		{
			char c1 = *s1;     // c1 - bukv, na kot ukaz s1
			char c2 = *s2;     // c2 - bukv, na kot ukaz s2
				if (c1 == '\0')    // esli dostignut konec slova, vyxodim iz cikla
					return c1 - c2;
				if (c1 != c2)      // esli bukvy raznye, vyxodim iz cikla
					return c1 - c2;
			*s1++;             // dvigaem ukazatel na sleduyuschuyu bukvu  v 1-m slove
		    *s2++;             // dvigaem ukazatel na sleduyuschuyu bukvu vo 2-m slove
		}
}
int alfasort(const void* slovo1, const void* slovo2) // compare two objects
{
	return comparesl(*(char**)slovo1, *(char**)slovo2);
}
int main()
{
char mass[100] = "does. goodby. dog.. cat.. car";
char* uknaslo[100]; // ykazatel on single words 
int che = 0;// number of words
uknaslo[0] = &mass[0];
che++;
for (int i = 0; mass[i] != '\0'; i++)// simvol konza stroki
{
	if ((mass[i] == ' ') || (mass[i] ==  '.'))
	{
		mass[i] = '\0';// razdel'aem stroky na otdeln slova
		uknaslo[che] = &mass[i + 1];
		che++;
	}
	
}
printf("che=%d", che);
qsort(uknaslo, che, sizeof(char*), alfasort);
	for (int i = 0; i < che; i++)
		printf("%s \n", uknaslo[i]);
}