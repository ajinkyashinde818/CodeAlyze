#include<stdio.h>

int main()
{
    int k,n,max_dis=-1;

    scanf("%d%d",&k,&n);

    int arr[n];

    scanf("%d",&arr[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]-arr[i-1]>max_dis)
            max_dis=arr[i]-arr[i-1];
    }

    if((k-arr[n-1])+arr[0]>max_dis)
        max_dis=(k-arr[n-1])+arr[0];

    printf("%d",k-max_dis);

    return 0;
}
