#include <stdio.h>

int main() {
    int N,D,X,i,n,Sum;

    
    scanf("%d",&N);
    
        int A[N+1];
    scanf("%d%d",&D,&X);
    
    
    for (i=1;i<N+1;i=i+1) {
    scanf("%d",&A[i]);
    }
    
    Sum = X;

    
    for (i=1;i<N+1;i=i+1) {
        for (n=0;1+n*A[i]<=D;n=n+1) {
            Sum = Sum +1;
        }
    }
    

    
      printf("%d\n",Sum);
    
    return 0;
}
