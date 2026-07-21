#include<stdio.h>
int main()
{
    int n, k, i, count = 0;
    scanf("%d %d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=k)
        {
            count++;
        }
    }
    printf("%d",count);
  return 0;
}
