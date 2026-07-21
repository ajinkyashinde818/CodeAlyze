#include<stdio.h>
int main()
{
    int i,k,n,max;
    scanf("%d %d",&k,&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=0;
    for(i=1;i<n;i++){
        if(a[i]-a[i-1]>=max) max=a[i]-a[i-1];
    }
    if((k-a[n-1])+a[0]>max) max=(k-a[n-1])+a[0];
    printf("%d",k-max);
    return 0;
}
