#include <stdio.h>
//Scitaet Kolvo Chisel Ymnog Na Seba
int skcyns(int a, int b){
int result = 1;
for (int i = 1; i < b; i++)
{
	result = result * a;
	if (result == b)
	{
		return i;
	}
}
return 0;
}
int main() 
{
	int a = 0;
	int b = 0;
	printf("INPUT A:");
	scanf("%d", &a);
	printf("INPUT B:");
	scanf("%d", &b);
	if (skcyns(a, b) >= 0)
		printf("%d ^ %d = %d\n", a, skcyns(a, b), b);
	else if (b == 1)
		printf("%d ^ 0 = %d \n", a, b);
	else printf("%d ^ not degree = %d\n", a, b);
}
