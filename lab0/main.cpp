# include <stdio.h>
int main()
{
	int a = 0,
		b = 0,
		c = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b); 
	scanf_s("%d", &c);

	printf("Result: %d \n", c - a);

	return  0;

}