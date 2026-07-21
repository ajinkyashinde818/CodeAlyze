#include <stdio.h>

int main(void){
    int K,P,N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&K,&P);
        if(K%P)
            printf("%d\n",K%P);
        else
            printf("%d\n",P);
    }
    return 0;
}
