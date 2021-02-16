#include <stdio.h>
#include "func.h"
int main()
{
    int a, b, c;
    printf("Input the side lengths: \n");
    scanf("%d %d %d", &a, &b, &c);
    check(a, b, c);
    return 0;
}

