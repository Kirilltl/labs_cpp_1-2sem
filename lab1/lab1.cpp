# include <stdio.h>
int main()
{
	double nums[10] = { 1.3545, 2.5654, 5.6575, 2.34, 4.222, 3.45, 3.555, 7.787, 1.367, 5.56 };

	for (int i = 0; i < 10;i++)
	{
		int cell = (int)nums[i]; // èçìåíåíèå òèïà äðîáíîãî íà öåëîå

		nums[i] = nums[i] - cell; // ÓÁÐÀËÈ ÖÅËÓÞ ×ÀÑÒÜ

		printf("%f  ---  %d \n", nums[i]  , cell);
	}

	// ÏÎÈÑÊ ÌÈÍÈÌÀËÜÍÎÉ ÄÐÎÁÍÎÉ ×ÀÑÒÈ
	double min = 1;
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
	}

	printf("mini %f", min);


	return 0;
}