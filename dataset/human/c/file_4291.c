#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int i,N,M;
    int a[100000];
    int ana[100000];
    unsigned long sum[100000];
    int mod=1000000007;

    scanf("%d %d", &N, &M);
    for(i=0;i<M;i++){
        scanf("%d", &a[i]);
        ana[a[i]]=1;
    }

    if(ana[N] != 1){
        sum[N]=1;
    }
    else{
        sum[N]=0;
    }
    if(ana[N-1] != 1){
        sum[N-1]=1;
    }
    else{
        sum[N-1]=0;
    }
    for(i=N-2;i>=0;i--){
        if(ana[i] == 1){
            sum[i] = 0;
            continue;
        }
        sum[i] = (sum[i+1]+sum[i+2]) % mod;
    }

    printf("%lu\n", sum[0]);
    return 0;
}
