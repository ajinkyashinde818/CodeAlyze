#include<stdio.h>

int main(){

    int K,N;
    int i;

    scanf("%d %d", &K, &N);

    //int a[N] = {0};
    int a[200000+1] = {0};
    int d;
    int ans=0;

    scanf("%d", &a[0]);
    for( i = 1; i <= N-1; i++ ){
        scanf("%d", &a[i]);
        d = a[i] - a[i-1];
        if( d > ans ){
            ans = d;
        }
    }

    if( K - (a[N-1] - a[0]) > ans ){
        ans = K - (a[N-1] - a[0]);
    }

    printf("%d\n", K-ans);

    return 0;
}
