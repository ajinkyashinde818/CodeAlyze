#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[1000000],i,j,k,n,d=0,d2=0;
    scanf("%d%d",&k,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    d=abs(arr[n-1]-arr[0]);
    for(j=0;j<n-1;j++)
    {
        d2=k-(arr[j+1]-arr[j]);
        if(d>d2)
        {
            d=d2;
        }
    }
    printf("%d\n",d);
    
    return 0;
}
