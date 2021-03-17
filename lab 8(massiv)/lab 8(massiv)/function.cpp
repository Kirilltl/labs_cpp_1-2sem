#include<stdio.h>
#include<stdlib.h>
int return_response()
{
	int len = 0;
	int capacity = 1;
	double* mass = (double*)malloc(sizeof(double));
	if (mass == NULL)
	{
		free(mass);
		exit(1);
	}
	double num;
	int res = scanf("%lf\n", &num);
	while (res >= 1)
	{
		mass[len++] = num;
		if (len >= capacity)
		{
			capacity *= 2;
			double* temp = (double*)realloc(mass, capacity * sizeof(double));
			if (temp != NULL)
			{
				mass = temp;
			}
			else
			{
				free(mass);
				exit(1);
			}
		}
		res = scanf("%lf\n", &num);
	}
	double max = 0.0;
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		double left = 0;
		double right = 0;
		if (i == 0)
		{
			left = mass[len - 1];
			right = mass[i + 1];
		}
		else if (i == len - 1)
		{
			left = mass[i - 1];
			right = mass[0];
		}
		else
		{
			left = mass[i - 1];
			right = mass[i + 1];
		}
		double a = mass[i] - left;
		double b = mass[i] - right;
		double c = a + b;
		if (c > max)
		{
			max = c;
			index = i;
		}

	}
	free(mass);
	return index;
}