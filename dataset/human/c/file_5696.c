#include <stdio.h>
#include <limits.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

int main()
{
    int R[200000], n;

    while(scanf("%d", &n) != EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &R[i]);

        int Max = INT_MIN;
        int Min = R[0];
        for(int i=1; i<n; i++)
        {
            Max = max(Max, R[i] - Min);
            Min = min(Min, R[i]);
        }
        printf("%d\n", Max);
    }
}
