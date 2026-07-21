#include<stdio.h>

int main(){
    int K,N,i,max,length;
    scanf("%d %d",&K,&N);
    int A[N];
    for(i=0;i<N;++i){
        scanf("%d ",&A[i]);
    }
    max=A[0]+K-A[N-1];//An~A1までの距離
    for(i=0;i<N-1;++i){
        length=A[i+1]-A[i];
        if(length>max){max=length;}
    }
    printf("%d\n",K-max);
    return 0;
}
