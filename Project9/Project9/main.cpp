#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main()
{
	int PolyLength_1, PolyLength_2;
	float Coef = 0;
	char Array[32];
	int flag = 0;
	PolyLength_1 = GetCharConvertToInt("Enter degree of first multinomial\n", "Error degree\n");
	if (PolyLength_1 > 10 || PolyLength_1 < 0)
	{
		printf("Error");
		exit(1);
	}
	float* Poly_1 = (float*)malloc((PolyLength_1 + 1) * sizeof(float));
	if (!Poly_1)
		exit(1);
	for (int i = PolyLength_1; i >= 0; i--)
	{
		sprintf(Array, "Enter factor x^%d = ", i);
		Coef = GetCharConvertToFloat(Array, "Error factor\n");
		if ((i == PolyLength_1) && (Coef == 0))
		{
			PolyLength_1--;
		}
		Poly_1[i] = Coef;
	}
	int PolyLength_1_TEMP = PolyLength_1;
	PolyLength_2 = GetCharConvertToInt("Enter degree of second multinomial\n", "Error degree\n");
	if (PolyLength_2 > 10 || PolyLength_2 < 0)
	{
		printf("Error");
		exit(1);
	}
	float* Poly_Remainder = (float*)malloc((PolyLength_2 + 1) * sizeof(float));
	float* Poly_2 = (float*)malloc((PolyLength_2 + 1) * sizeof(float));
	if (!Poly_2)
		exit(1);
	float* Poly_Result = (float*)malloc(((abs(PolyLength_1 - PolyLength_2) + 1) + 1) * sizeof(float));
	for (int i = PolyLength_2; i >= 0; i--)
	{
		sprintf(Array, "Enter factor x^%d = ", i);
		Coef = GetCharConvertToFloat(Array, "Error factor\n");
		if ((i == PolyLength_2) && (Coef == 0))
		{
			PolyLength_2--;
			if (PolyLength_2 == 0)
			{
				printf("Division by '0'");
				exit(1);
			}
		}
		Poly_2[i] = Coef;
	}
	int PolyLength_2_TEMP = PolyLength_2;
	DividePolynomsWithRemainder(Poly_1, PolyLength_1, Poly_2, PolyLength_2, Poly_Result, Poly_Remainder);
	printf("\nResult of division (factors) = ");
	int Check = PolyLength_1 - PolyLength_2;
	int TMP = 0;
	if ((PolyLength_1 - PolyLength_2) < 0) {
		Check = 0;
	}
	for (int i = 0; i < (Check); i++)
		if (Poly_Result[i] != 0) {
			TMP = printf("%lf*x^%d ", Poly_Result[i], Check - i);
			printf("%d", TMP);
			if ((TMP == 0) || (TMP < 0)) {
				printf("0");
			}
		}
	TMP = 0;
	for (int i = Check; i <= (Check); i++)
		TMP = printf("%lf ", Poly_Result[i]);
	if ((TMP == 0) || (TMP < 0)) {
		printf("0");
	}
	printf("\nRest (factors) = ");
	TMP = 0;
	for (int i = 0; i < (PolyLength_2 - 1); i++)
		if (Poly_Remainder[i] != 0) {

			TMP = printf("%lf*x^%d ", Poly_Remainder[i], PolyLength_2 - i - 1);
			if ((TMP == 0) || (TMP < 0)) {
				printf("0");
			}
		}
	TMP = 0;
	for (int i = abs(PolyLength_2 - 1); i <= (PolyLength_2 - 1); i++)
		TMP = printf("%lf ", Poly_Remainder[i]);
	if ((TMP == 0) || (TMP < 0)) {
		printf("0");
	}
	//free(Poly_Result);
	//free(Poly_Remainder);
	//free(Poly_1);
	//free(Poly_2);
}