#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i,j;
    int N;
    int *A; 
    int min,flag; 
    long int ans=0;

    scanf("%d",&N);
    A=malloc(sizeof(int)*N);

    for(i=0;i<N;i++){
        scanf("%d ",&A[i]);
    }

    for(i=0;i<N-1;i++){
        if(A[i]<0){
            A[i]=-A[i];
            A[i+1]=-A[i+1];
        }
    }
    if(A[N-1]<0){
        min=A[0];
        flag=0;
        for(i=1;i<N-1;i++){
            if(A[i]<min){
                min=A[i];
                flag=i;
            }
        }
        if(min<-A[N-1]){
            A[flag]=-A[flag];
            A[N-1]=-A[N-1];
        }
    }

    for(i=0;i<N;i++){
        ans+=A[i];
    }
    printf("%lu",ans);
    return 0;
}
