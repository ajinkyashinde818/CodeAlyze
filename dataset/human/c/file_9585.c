#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, d, x, a[100];
    scanf("%d", &n);
    scanf("%d%d", &d, &x);
    int i, j;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int eaten = 0;
    for (i=0; i<n; i++)
    {
        for (j=0; j*a[i]+1<=d; j++)
        {
            eaten ++;
        }
    }
    printf("%d\n", eaten + x);
    return 0;
}
