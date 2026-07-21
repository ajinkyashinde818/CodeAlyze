#include <stdio.h>
int main(void){
    int N,K,P,i,win;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&K,&P);
        win=K%P;
        if(K%P==0)
            win=P;
        printf("%d\n",win);
    }
    return 0;
}
