#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char x, y;
    scanf("%c %c", &x, &y);
    if (x < y)
    {
        printf("<\n");
    }
    else if (x > y)
    {
        printf(">\n");
    }
    else
    {
        printf("=\n");
    }
    return 0;
}
