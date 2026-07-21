#include <stdio.h>
#include <stdlib.h>


int main(){         //回答見た

    int K, N;
    scanf("%d %d", &K, &N);

    int A[N];
    int i;
    for(i = 0; i<N; i++){
        scanf("%d",&A[i]);
    }

    int tmp = 0;
    for(i = 0; i<N-1; i++){
        if((A[i+1]-A[i]) > tmp){
            tmp = A[i+1]-A[i];
        }
    }
    if(A[0] + (K-A[i]) > tmp){
        tmp = A[0] + (K-A[i]);
    }

    printf("%d",K-tmp);

   return 0;
}
