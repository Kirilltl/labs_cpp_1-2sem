#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "func.h"
int main()
{
	int	MAX_I = 0;//STR
	int	MAX_J = 0;//STL
	printf("vvedite MAX_I & MAX_J \n");
	int r=scanf("%d", &MAX_I);
	r=scanf("%d", &MAX_J);

	double res = return_response( MAX_I,MAX_J);
	printf("res = %lf \n", res);

}