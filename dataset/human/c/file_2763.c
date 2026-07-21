#include <stdio.h>

int main(){
    int K, S, i, j, k, cnt=0;

    scanf("%d %d", &K, &S);

    for(i=0; i<=K; i++){
        for(j=0; j<=K; j++){
            k = S-i-j;
            if(0<=k && k <= K)
                cnt++;
        }
    }

    printf("%d\n", cnt);
}
