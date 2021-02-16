#include<stdio.h>
struct Numb
{
	float p;
	Numb* next;
};
int main() {

	Numb* n1 = (Numb*)malloc(sizeof(Numb));
	n1->p = 1;

	Numb* n2 = (Numb*)malloc(sizeof(Numb));
	n2->p = 2;
	n1->next = n2;

	float p[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	float max = 0;
	for (int i = 1; i < 11; i++)
	{
		float a = p[i] - p[i - 1];
		float b = p[i] - p[i + 1];
		float c = a + b;
		if (c > max) {
			max = c;
		}
	
	}
	printf("%f", max);
}