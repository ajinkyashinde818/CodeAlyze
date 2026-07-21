#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    int i;
    for(i=100;1<=i;i--){
        if(A%i==0 && B%i==0){
            K -= 1;
            if(K==0){
                printf("%d",i);
                i=0;
            }
        }
    }
    return 0;
}
