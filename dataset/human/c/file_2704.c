#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int k, s;
    int x, y, z;
    int c = 0;
    scanf("%d %d", &k, &s);
    for (x = 0; x <= k; ++x)
        for (y = 0; y <= k; ++y)
            if (s - x - y >= 0 && s - x - y <= k)
                c++;
    printf("%d\n", c);
}
