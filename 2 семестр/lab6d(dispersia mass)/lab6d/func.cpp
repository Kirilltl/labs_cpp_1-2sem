#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double find_disp(int MAX_I, int MAX_J, double* mass, int window)
{
	double res = 0;
	for (int i = 0; i < MAX_I; i++)
	{
		double sum = 0;
		int count = 0;
		for (int j = 0; j < MAX_J; j++)
		{
			if (j % window == 0)
			{
				double elem = *(mass + i * MAX_I + j);
				sum = sum + elem;
				count++;
			}
		}
		double xsr = sum / count;
		double sumkvad = 0;
		for (int j = 0; j < MAX_J; j++)
		{
			if (j % window == 0)
			{
				sumkvad = sumkvad + pow(*(mass + i * MAX_I + j) - xsr, 2);
			}
		}
		double s = sqrt(sumkvad / (count - 1.0));
		if (s > res)
			res = s;
		printf("s = %lf \n", s);
	}
	return res;
}
