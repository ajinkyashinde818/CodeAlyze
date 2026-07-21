#include<stdio.h>
int main(void){
    int N,K,P,a;
    scanf("%d",&N);
    for(a=1; a<=N; a++){
        scanf("%d %d",&K,&P);
        if(K%P==0)
        printf("%d\n",P);
        else
        printf("%d\n",K%P);
    }
    return 0;
}
