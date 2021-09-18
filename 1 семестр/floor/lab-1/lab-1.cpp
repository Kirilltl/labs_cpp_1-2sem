# include <stdio.h>
int floor(float a)
{
	int res = (int)a;
	if (a < 0)
		res = a - 1;
	return res;
}
int main()
{
	float nums[10];
	int i = 0;
	for ( ; ; )
	{
		printf("Input number:");
		while (scanf("%f", &nums[i]) != 1)
		{ 
			printf("Invalid number! Try again! \n");
			while (getchar() != '\n');
	    }
		if (nums[i] < 0)
		{
			printf("Invalid number! \n");
			continue;
		}
		else
		{
			nums[i] = nums[i] - floor(nums[i]);
			printf("Drob.chast of this number: %f \n", nums[i]);
			if (i == 9)
			{
				break;
			}
			i++;
		}
	}
	double min = 1;
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
	}
	printf("Min drob.chast: %f", min);
	return 0;
}
