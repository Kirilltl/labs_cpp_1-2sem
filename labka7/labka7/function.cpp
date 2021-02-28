#include <stdio.h>
#define Max 46341
int check(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a >= Max || b >= Max || c >= Max)
    {
        return 1;
    }
    a *= a;
    b *= b;
    c *= c;
    if ((a == b + c) || (b == a + c) || (c == b + a))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}