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
	float nums[10] = { -1.98, 2.565,-0.3, 2.34, -4.222, 3.45, 3.555,1.3, 1.367, 5.56 };
	for (int i = 0; i < 10; i++)
	{
		printf(" The number i entered: %f \n ", nums[i]);
		nums[i] = nums[i] - floor(nums[i]);
		printf(" Drob.chast of this number: %f \n ",nums[i]);
	}
    double min = 1;
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] < min)
		{
			min =  nums[i];
		}
	}
	printf(" Min drob.chast: %f ", min);
	return 0;
}
