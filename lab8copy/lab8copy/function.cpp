#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double find_deviation(int MAX_I, int MAX_J, double* mass)
{
	double res = 0;
	for (int i = 0; i < MAX_I; i++)
	{
		double sum = 0;
		for (int j = 0; j < MAX_J; j++)
		{
			double elem = *(mass + i * MAX_I + j);
			sum = sum + elem;
		}
		double xsr = sum / MAX_J;
		double sumkvad = 0;
		for (int j = 0; j < MAX_J; j++)
			sumkvad = sumkvad + pow(*(mass + i * MAX_I + j) - xsr, 2);
		double sigma = sqrt(sumkvad / MAX_J);
		if (sigma > res)
			res = sigma;
		printf("sigma = %lf \n", sigma);
	}
	return res;
}
