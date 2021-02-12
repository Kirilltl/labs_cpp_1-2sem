#include <stdio.h>
#define MAX 46340 // İÒÎ ×ÈÑËÎ Â ÊÂÀÄĞÀÒÅ ÌÀÊÑ ÈÍÒ

int check(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("No it is not a triangle \n");
        return 1;
    }
    if (a >= MAX || b >= MAX || c >= MAX)
    {
        printf("error \n");
        return 2;
    }

    a *= a;
    b *= b;
    c *= c;

    if ((a == b + c) || (b == a + c) || (c == b + a))
    {
        printf("Yes it is a right-angled triangle \n");
        return 0;

    }
    else
    {
        printf("No it is not a right-angled triangle \n");
        return 3;
    }
}