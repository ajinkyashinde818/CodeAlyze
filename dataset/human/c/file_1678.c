#include<stdio.h>

int main(){
    int i,n,d=0;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
        d=d+b[i];
    }
    int g;
    for(i=0;i<n-1;i++){
        scanf("%d",&c[i]);
    }
    for(i=0;i<n-1;i++){
        if(a[i]==a[i+1]-1){
            g=a[i];
            d=d+c[g-1];
        }
    }

    printf("%d",d);
}
