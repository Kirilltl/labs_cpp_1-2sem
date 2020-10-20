#include<stdio.h>


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


void qsort(char* uknaslo[], int che)
{
	
	for (int j = 0; j < (che - 1); j++)// ne vyti za granicy mass
	{
		for (int i = 0; i < (che - 1); i++)
		{
			int result = comparesl(uknaslo[i], uknaslo[i + 1]); // vozvrashaet chislo 
			//printf("%s %s  ->  %d \n", uknaslo[i], uknaslo[i+1], result);
			char* temp;
			if (result > 0) // nado pomenjat slova mestami
			{
				temp = uknaslo[i];
				uknaslo[i] = uknaslo[i + 1];
				uknaslo[i + 1] = temp;
			}
			//printf("%s %s  changed! \n", uknaslo[i], uknaslo[i + 1]);
		}
	}




}




int main()
{
char mass[] = "does goodby.,. dog., cat car";
char* uknaslo[100]; // ykazatel on single words 
int che = 0;// number of words
uknaslo[0] = &mass[0];
che++;
for (int i = 0; mass[i] != '\0'; i++)// simvol konza stroki
{
	if ((mass[i] == ' ') || (mass[i] ==  '.') || (mass[i] == ','))
	{
		mass[i] = '\0'; // razdel'aem stroky na otdeln slova
		uknaslo[che] = &mass[i + 1]; // shob nachalo slovo c bukv a ne probela
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