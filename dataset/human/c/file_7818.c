#include <stdio.h>
int main(void){
    int i,N,x;

    scanf("%d",&N);
    int K[N];
    int P[N];

    for(i=0;i<N;i++){
        scanf("%d %d",&K[i],&P[i]);
    }
    for(i=0;i<N;i++){
        if(K[i]%P[i]==0)
           printf("%d",P[i]);
        else if(K[i]<P[i])
            printf("%d",K[i]);
        else
            printf("%d",K[i]%P[i]);
        printf("\n");
    }

    return 0;
}
