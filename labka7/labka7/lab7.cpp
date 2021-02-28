#include <stdio.h>
#include "func.h"
int main()
{
    double a, b, c;
    printf("Input the side lengths: \n");
    int res = scanf("%lf %lf %lf", &a, &b, &c);
    if (check(a, b, c) == 0)
        printf("Yes, it's a right-angled triangle \n");
    else
        printf("No, it isn't a right-angled triangle \n");
    return 0;
}