#include<stdio.h>
#define SIZE10 100000

typedef long long int ll;
typedef unsigned char u8;



int main(void){
    int N = 0;
    int K = 0;
    int h[SIZE10];
    int ans = 0;
    int i = 0, j = 0;

    scanf("%d %d", &N, &K);
    for(i = 0; i < N; i++){
        scanf("%d", &h[i]);
    }

    for(i = 0; i < N; i++){
        if(h[i] >= K){
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}
