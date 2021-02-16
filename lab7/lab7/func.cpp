#include <stdio.h>
#define MAX 46341
int check(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("No, it isn't a triangle \n");
        return 1;
    }
    if (a >= MAX || b >= MAX || c >= MAX)
    {
        printf("Error \n");
        return 2;
    }
    a *= a;
    b *= b;
    c *= c;
    if ((a == b + c) || (b == a + c) || (c == b + a))
    {
        printf("Yes, it's a right-angled triangle \n");
        return 0;
    }
    else
    {
        printf("No, it isn't a right-angled triangle \n");
        return 3;
    }
}