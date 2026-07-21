#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a * b == c * d)
    {
        printf("%d\n", a * b);
    }
    else
    {
        printf("%d\n", a * b > c * d ? a * b : c * d);
    }
    return 0;
}
