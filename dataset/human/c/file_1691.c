#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d",&c[i]);
    }
    int sum=0;
    for(i=1;i<=n;i++){
        sum=sum+b[i];
    }
    int sum1=0;
    for(i=1;i<n;i++){
        if(a[i]+1==a[i+1]){
            sum1=sum1+c[a[i]];
        }
    }
    printf("%d\n",sum+sum1);
    return 0;
}
