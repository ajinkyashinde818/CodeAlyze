#include<stdio.h>

int min(int A,int B){
    if(A>=B){
        return A;
    }else{
        return B;
    }
};

int main(){
    int A,B,K;
    int i;
    int result;
    int count=0;
    scanf("%d %d %d",&A,&B,&K);
    for(i=min(A,B);i>=1;i--){
        if(A%i==0 && B%i==0){
            count+=1;
            if(count==K){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
