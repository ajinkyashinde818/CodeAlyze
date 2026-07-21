#include <stdio.h>

int main(void)
{
    int n=0,sum=0;
    int a[25]={},b[25]={},c[25]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n-1;i++) scanf("%d",&c[i]);

    for(int i=0;i<n;i++){
        sum+=b[i];
        if(a[i]+1==a[i+1]) sum+=c[a[i]-1];
    }

    printf("%d",sum);
    return 0;
}
