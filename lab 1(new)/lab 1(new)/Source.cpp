# include <stdio.h>
int floor(float a) 
{
	int res = (int)a;
	if (a < 0)
		res=a-1;
	return res;
}
int main()
{
float nums[10];
	for (int i = 0; i < 10; i++)
	{
		printf("Input number:");
		scanf("%f", &nums[i]);
		if (nums[i] < 0)
		{
			printf("you can not enter negative numbers \n");
			nums[i] = 1;
			printf("\n");
		}
		else
		{
			nums[i] = nums[i] - floor(nums[i]);
			printf("Drob.chast of this number: %f \n", nums[i]);
			printf("\n");
		}
	}
double min = 1;
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] < min)
		{
			min =  nums[i];
		}
	}
	printf("Min drob.chast: %f", min);
	return 0;
}
