#include<stdio.h>

int main(){
    int N,K,P,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&K,&P);
        if(K%P==0){
            printf("%d\n",P);
        }else{
            printf("%d\n",K%P);
        }
    }
    return 0;
}
