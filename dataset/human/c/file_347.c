#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long n, q;
    scanf("%ld %ld", &n, &q);

    if (n >= 10)
    {
        printf("%ld\n", q);
    }
    else
    {
        printf("%ld\n", q + 100 * (10 - n));
    }

    return 0;
}
