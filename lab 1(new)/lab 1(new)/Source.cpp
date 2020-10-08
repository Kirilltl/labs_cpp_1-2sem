# include <stdio.h>
# include <math.h>
int main()
{
    float nums[10] = { -1.99, 2.565,-0.3, 2.34, -4.222, 3.45, 3.555,1, 1.367, 5.56 };
        for (int i = 0; i < 10; i++)
	  {
		nums[i] = nums[i] - floor(nums[i]);
		printf("drob. chast: %f \n",nums[i]);
      }

	       // poisk minimal'noj drobnoj chasti
	double min = 1;
	for (int i = 0; i < 10; i++)
	{

		if (nums[i] < min)
		{
			min =  nums[i];
		}
	}
	printf("min drob chast: %f", min);
	return 0;
}