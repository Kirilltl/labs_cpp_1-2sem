#include <stdio.h>
int find_power(int a, int b)
{
	int result = 1;
	for (int i = 1;i != b; i++)  //  Second condition always true,not example that make it false 
	    {
			result *= a;
			if (result == b)
				{
					return i;
				}
	    }
	return -1;
}
int main() 
{
	int a = 0;
	int b = 0;
	printf("INPUT A:");
	scanf("%d", &a);
	printf("INPUT B:");
	scanf("%d", &b);
	if (find_power(a, b) >= 0)
		printf("%d ^ %d = %d\n", a, find_power(a, b), b);
	else if (b == 1)
		printf("%d ^ 0 = %d \n", a, b);
	else printf("Not power,sorry \n");
}
