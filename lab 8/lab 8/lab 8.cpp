#include<stdio.h>
#include "func.h"
int main() {
	Answer ans = return_response();
	printf("The number of this element = %d\n", ans.index);
	printf("Max.sum of the differences = %lf\n", ans.max);
}