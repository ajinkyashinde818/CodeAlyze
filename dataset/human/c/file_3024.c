#include <stdio.h>
int main(void){
    int K,N;
    scanf("%d%d",&K,&N);
    int A[N];
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    int MAXlength=K-A[N-1]+A[0],W;
    for(i=0;i<N-1;i++){
        W=A[i+1]-A[i];
        if(MAXlength<W){
            MAXlength=W;
        }
    }
    printf("%d\n",K-MAXlength);
}
