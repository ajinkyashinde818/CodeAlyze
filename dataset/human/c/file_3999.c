#include<stdio.h>

int main(void){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    for(int i=A;i>=1;i--){
        if(A%i==0 && B%i==0){
            K--;
        }
        if(K==0){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
