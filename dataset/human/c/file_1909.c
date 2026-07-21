#include<stdio.h>

int main(){

    int N=0;
    int A[21]={};
    int B[21]={};
    int C[20]={};
    int sum=0;
    int kari=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
        for(int i=0;i<N-1;i++){
        scanf("%d",&C[i]);
    }

    for(int i=0;i<N;i++){
        if(A[i+1]-A[i]==1){
            kari=A[i]-1;
            sum += C[kari];
        }

        sum += B[i];

    }


    printf("%d\n",sum);

    return 0;
}
