#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
bool CheckInput(char s)
{
	return (((s >= '0') && (s <= '9')) || (s == '-') || (s == '.'));
}
int GetCharConvertToInt(const char* Caption, const char* ErrorCaption)
{
	char Char;
	int Size = 100;
	char* Str;
	char* StrTemp;
	int i = 0;

	printf(Caption);
	Str = (char*)malloc(Size * sizeof(char));
	if (!Str)
		return 0;
	while (1)
	{
		Char = getchar();
		if (Char == '\n')
			Char = '\0';
		if (!CheckInput(Char) && Char)
		{
			while (getchar() != '\n');
			printf(ErrorCaption);
			i = 0;
			continue;
		}
		if (i + 1 == Size)
		{
			Size += 100;

			StrTemp = (char*)realloc(Str, Size * sizeof(char));
			if (!StrTemp)
			{
				free(Str);
				free(StrTemp);
				return 0;
			}
			Str = StrTemp;
		}
		Str[i] = Char;
		if (!Char)
			break;
		i++;
	}

	int InputResult = atoi(Str);
	free(Str);

	return InputResult;
}

float GetCharConvertToFloat(const char* Caption, const char* ErrorCaption)
{
	char Char;
	int Size = 100;
	char* Str;
	char* StrTemp;
	int i = 0;

	printf(Caption);
	Str = (char*)malloc(Size * sizeof(char));
	if (!Str)
		return 0;
	while (1)
	{
		Char = getchar();
		if (Char == '\n')
			Char = '\0';
		if (!CheckInput(Char) && Char)
		{
			while (getchar() != '\n');
			printf(ErrorCaption);
			i = 0;
			continue;
		}
		if (i + 1 == Size)
		{
			Size += 100;

			StrTemp = (char*)realloc(Str, Size * sizeof(char));
			if (!StrTemp)
			{
				free(Str);
				free(StrTemp);
				return 0;
			}
			Str = StrTemp;
		}
		Str[i] = Char;
		if (!Char)
			break;
		i++;
	}

	float InputResult = atof(Str);
	free(Str);

	return InputResult;
}

void DividePolynomsWithRemainder(float* Poly_1, int PolyLength_1, float* Poly_2, int PolyLength_2, float* Poly_Result, float* Poly_Remainder)

{

	int LengthDifference = abs(PolyLength_1 - PolyLength_2);
	int Temp = LengthDifference;

	if (PolyLength_2 > PolyLength_1)
	{

		for (int i = PolyLength_2; i >= 0; i--)
		{


			*Poly_Result = 0;
			Poly_Result++;

		}

		for (int i = 0; i < PolyLength_2 - PolyLength_1 - 1; i++) {
			*Poly_Remainder = 0;
			Poly_Remainder++;
		}

		for (int i = PolyLength_1; i >= 0; i--) {

			*Poly_Remainder = Poly_1[i];
			Poly_Remainder++;
		}
		*Poly_Remainder = NULL;
	}
	else
	{
		float* Result = (float*)malloc((PolyLength_1 - PolyLength_2 + 3) * sizeof(float));
		if (!Result)
			exit(1);


		do
		{
			float Digit = (Poly_1[PolyLength_1] / Poly_2[PolyLength_2]);
			int Temp_2 = PolyLength_2;
			Result[Temp] = Digit;
			Temp--;
			for (int i = PolyLength_1; i >= (PolyLength_1 - PolyLength_2); i--)
			{

				Poly_1[i] = (Poly_1[i] - (Digit * Poly_2[Temp_2]));
				Temp_2--;
			}
			PolyLength_1--;
			if (PolyLength_1 < PolyLength_2)
				break;
		} while (PolyLength_1 >= PolyLength_2);

		for (int i = LengthDifference; i >= 0; i--)

		{

			*Poly_Result = Result[i];
			Poly_Result++;
		}
		*Poly_Result = NULL;

		for (int i = PolyLength_1; i >= 0; i--) {
			*Poly_Remainder = Poly_1[i];
			Poly_Remainder++;
		}
		*Poly_Remainder = NULL;
		free(Result);
	}

}