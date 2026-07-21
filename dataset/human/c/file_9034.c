#include<stdio.h>
int main()
{
    int a[100000],n,k,l,j=0,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=k)
            j++;
    }
    printf("%d\n",j);
    return 0;
}
