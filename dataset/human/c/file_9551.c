#include<stdio.h>

int main(void){
    int N,D,X,T,i,x;
    int A[100];
    
    scanf("%d%d%d",&N,&D,&X);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        x=(D-1)/A[i];
        T +=x+1;
    }
    T += X;
    printf("%d\n",T);
     return 0;
}
