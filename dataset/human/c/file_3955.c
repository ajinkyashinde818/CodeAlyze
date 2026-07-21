#include<stdio.h>

int Max(int a,int b){
    if(a>b) return a;
    return b;
}


int main(void){
    int A,B,K,count=0;
    scanf("%d %d %d",&A,&B,&K);

    for(int i=Max(A,B);i>=0;i--){
        if(A%i==0&&B%i==0){
            count++;
            if(count==K){
                printf("%d",i);
                break;
            }
        }
        
    }

    return 0;
}
