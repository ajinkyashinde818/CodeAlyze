#include <stdio.h>
#define NMAX 10000
int main()
{
    int a[NMAX];
    int i = 0;

    for (i = 0; i < NMAX; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 0)
            break;
        printf("Case %d: %d\n", i + 1, a[i]);
    }
    return 0;
}
