#include<stdio.h>

int main(){
    int N, M;
    int a[110000];
    int sum[110000];
    int delta = 110000;
    int roop;
    int i,j;
    int ans = 0;

    scanf("%d %d", &N, &M);

    for(i=0; i<=N; i++){
        sum[i] = 1;
    }

    for(i=0; i<M; i++){
        scanf("%d", &a[i]);
        sum[a[i]] = 0;
    }

    if(M>1){
        for(i=1; i<M; i++){
            if(delta > (a[i]-a[i-1])){
                delta = a[i] - a[i-1];
            }
        }
    }

    for(i=2; i<=N; i++){
        if(sum[i] != 0){
            sum[i] = (sum[i-1]+sum[i-2])%1000000007;
        }

    }

    if(delta == 1){
        printf("0");
    }else{
        printf("%d", sum[N]);
    }

    return 0;

}
