#include<stdio.h>
#include <math.h>
int main(){
    int k, n, i;
    scanf("%d %d",&k,&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max = a[1] - a[0];
    for(i=2;i<n;i++){
        if(max<a[i]-a[i-1]){
            max = a[i]-a[i-1];
        }
    }
    if(max<k-a[n-1]+a[0]){
        max = k-a[n-1]+a[0];
    }
    printf("%d",k-max);
    return 0;
}
