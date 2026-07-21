#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int f = 0;
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a == b)
        {
            f++;
        }
        else
        {
            f = 0;
        }

        if (f >= 3)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}
