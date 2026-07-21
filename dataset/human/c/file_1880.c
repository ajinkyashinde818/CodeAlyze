#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    int N,i;
    scanf("%d",&N);
    int A[51],B[51],C[51];   
    int S;
    S=0;
    for(i=0;i<N;i++){
    	scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
    	scanf("%d",&B[i]);
    }
    for(i=0;i<N-1;i++){
    	scanf("%d",&C[i]);
    }
    for(i=0;i<N;i++){
    	S=S+B[A[i]-1];
    }
     for(i=1;i<N;i++){
    	if((A[i]-A[i-1]==1)){
    		S=S+C[A[i-1]-1];
    	}
    }
    printf("%d\n",S);
    return 0;
}
