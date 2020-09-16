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
	printf("%d\n", f(25, 5));
	printf("%d\n", f(27, 3));
	printf("%d\n", f(23, 5));
	printf("%d\n", f(128, 2));


}