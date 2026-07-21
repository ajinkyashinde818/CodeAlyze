#include <stdio.h>

int main(void)
{
    int k,n;
    scanf("%d %d",&k,&n);
    int a[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int tmp=a[0];
    for(int i=0;i<n;i++){
        a[i]-=tmp;
    }
    int d=k-a[n-1];
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]>d){
            d=a[i+1]-a[i];
        }
    }
    printf("%d",k-d);
}
