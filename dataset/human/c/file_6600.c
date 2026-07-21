#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,min,max=-1000000000;
    scanf("%d",&n);
    int R[n];
    scanf("%d",&R[0]);
    min = R[0];
    for(int i=1;i<n;i++)
    {
        scanf("%d",&R[i]);
        (R[i]-min)<max ? (max = max) : (max = R[i]-min);
        (R[i])<min ? (min = R[i]) : (min = min);
    }
    printf("%d\n",max);
    return 0;
}
