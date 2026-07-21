#include<stdio.h>

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    int a[n];
    int max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n+1;i++){
        if(i==n){
            if(max<k-a[n-1]+a[0]){
                max=k-a[n-1]+a[0];
            }
        }else{
            if(max<a[i]-a[i-1]){
                max=a[i]-a[i-1];
            }
        }
    }
    printf("%d",k-max);
    return 0;
}
