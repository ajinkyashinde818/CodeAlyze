#include<stdio.h>
#include<string.h>

int main(void){
    int k,n,i,max=0;
    scanf("%d%d",&k,&n);
    int a[n];
    scanf("%d",&a[0]);
    for(i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]-a[i-1]>max){
            max = a[i]-a[i-1];
        }
    }
    if(k-a[n-1]+a[0]>max){
        max = k-a[n-1]+a[0];
    }
    printf("%d",k-max);
    return 0;
}
