#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int K, S;

    scanf("%d%d", &K, &S);

    int ans = 0;

    for(int i = 0; i <= K; i++){
        if(i > S){
            break;
        }
        for(int j = 0; j <= K; j++){
            if(i + j > S){
                break;
            }
            if(S - i - j >= 0 && S - i - j <= K){
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
