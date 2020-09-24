#include <stdio.h>

int f(int a, int b)
{
	int result = 1;
for (int i = 1; i < 10; i++)
	{
		result = result * b;
		if (result == a)
		{
			return i;
		}
	}
return -1;
}


int main()
{
	int b=0;
	int a = 0;
	scanf("%d", &a);
	scanf("%d",&b );


	//if (f(a, b) >= 0)
		printf("f(%d,%d)= %d\n", a, b, f(a, b));
	//else
	//	printf("Error\n");


	
}