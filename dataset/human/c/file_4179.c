#include <stdio.h>
int main(void)
{
    int a, b, k;
    int i = 1, j = 0, g[100];
    scanf("%d%d%d", &a, &b, &k);
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
        {
            g[j] = i;
            j++;
        }
        i++;
    }
    printf("%d\n", g[j - k]);
    return 0;
}
