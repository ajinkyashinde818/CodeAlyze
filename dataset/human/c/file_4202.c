#include<stdio.h>
#include<algorithm>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    long memo[n + 1];
    for(int i = 0; i < n + 1; i++){
        memo[i] = -1;
    }
    int destroied[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &destroied[i]);
    }
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 0; i < m; i++){
        memo[destroied[i]] = 0;
    }
    for(int i = 2; i < n + 1; i++){
        if(memo[i] != 0){
            memo[i] = memo[i - 2] + memo[i - 1];
            if(memo[i] >= 1000000007){
                memo[i] = memo[i] % 1000000007;
            }
        }
    }
    printf("%ld", memo[n]);
}
