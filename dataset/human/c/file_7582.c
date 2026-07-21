#include <stdio.h>

int main()
{
    int v[10000];
    int i = 0, j = 0;

    do
    {
         scanf("%d", &v[i]);
         i++;
    }while(v[i - 1] != 0);

    while(j < i -1)
    {
        printf("Case %d: %d\n", j + 1, v[j]);
        j++;
    }

    return 0;
}
