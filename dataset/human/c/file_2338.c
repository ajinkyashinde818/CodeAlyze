#include<stdio.h>
#define MAX_NUM 100000

int main(void){

    int N,K,i,t=0;
    long int S,ans[MAX_NUM+1];

    scanf("%d %d %ld",&N,&K,&S);

    for(i = 0;i < N;i++){
        if(t <= K-1){
            ans[i] = S;
            t++;
        }else{
            if(S < MAX_NUM){
                ans[i] = MAX_NUM+1;
            }else{
                ans[i] = MAX_NUM-1;
            }
        }
    }

    for(i = 0;i < N;i++){
        printf("%ld ",ans[i]);
    }
    printf("\n");
    return 0;
}
