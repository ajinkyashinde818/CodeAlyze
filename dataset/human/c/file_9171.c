#include<stdio.h>

int main()
{
    int n,k,i;
    int count = 0;
    scanf("%d %d", &n, &k);
    int h[n + 1];

    for (i = 1; i < n + 1;i++)
        scanf("%d", &h[i]);

    for (i = 1; i < n + 1;i++)
        if(h[i]>=k)
            count++;
    printf("%d\n",count);
    return 0;
}
