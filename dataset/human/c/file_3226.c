#include<stdio.h>

#define MAX_N 1000000

int main(void){

    long int K,N,A[MAX_N],i,ans,reduce_way = 0,longest_way = 0,tmp;

    scanf("%ld %ld",&K,&N);
    for(i = 0;i < N;i++){
        scanf("%ld",&A[i]);
        if(i > 0){
            tmp = A[i] - A[i-1];
            if(tmp > longest_way){
                longest_way = tmp;
                reduce_way = i;
            }
        }
    }

    tmp = K - A[N-1] + A[0];
    if(tmp > longest_way){
        longest_way = tmp;
        reduce_way = 0;
    }

    if(reduce_way == 0){
        ans = A[N-1] - A[0];
    }else{
        ans = K - longest_way;
    }

    printf("%ld\n",ans);
    return 0;
}
