#include <stdio.h>

int main(void)
{
    int N,i,manzoku=0,tmp;
    int A[50],B[50],C[50];

    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    for(i=0; i<N; i++){
        scanf("%d",&B[i]);
    }
    for(i=0; i<N-1; i++){
        scanf("%d",&C[i]);
    }

    for(i=0; i<N; i++){
        manzoku += B[i];
        //printf("B[%d] = %d\n",i,B[i]);
        if((A[i]+1 == A[i+1])&& (i!=N-1)){
            //printf("%d\n",i);
            tmp = A[i]-1;
            manzoku += C[tmp];
            //printf("A[%d] = %d, A[%d+1] = %d\n",i,A[i],i,A[i+1]);
            //printf("C[%d] = %d\n",i,C[tmp]);
        }
    }

    printf("%d\n",manzoku);

    return 0;
}
