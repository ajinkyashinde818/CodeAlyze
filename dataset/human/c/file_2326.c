#include<stdio.h>

int main(void){
    int n,k,s,i;
    scanf("%d%d%d",&n,&k,&s);
    int a[n];
    for(i=0;i<k;i++){
        a[i] = s;
    }
    for(;i<n;i++){
        if(s==1000000000){
            a[i] = 1;
        }else{
            a[i] = 1000000000;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
