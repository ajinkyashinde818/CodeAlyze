#include<stdio.h>

int main(){

    long int ans = 1;

    int N, M;
    scanf("%d%d", &N, &M);

    int a[M+2];

    a[0] = -1;
    a[M + 1] = N+1;

    for (int i = 1; i < M+1; i++){

        scanf("%d", &a[i]);

        if(a[i] == a[i-1] + 1){
            ans = 0;
        }
    }

    if(ans == 1){

        long int pattern[N+1];

        pattern[0] = 1;
        pattern[1] = 1;
        pattern[2] = 2;

        for (int i = 3; i < N+1; i++){
            pattern[i] = (pattern[i - 1] + pattern[i - 2]) % 1000000007;

            //printf("pattern[%d] = %ld\n", i, pattern[i]);
        }

        for (int i = 1; i < M+2; i++){

            ans = (ans * pattern[a[i] - a[i - 1] - 2]) % 1000000007;
        }
    }

    printf("%d", ans);

    return 0;
}
