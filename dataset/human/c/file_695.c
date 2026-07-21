#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N, M;

    scanf("%d%d", &N, &M);

    char A[N][N+1], B[M][M+1];

    for(int i = 0; i < N; i++){
        scanf("%s", A[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%s", B[i]);
    }

    int t = 0;

    for(int i = 0; i <= N-M; i++){
        if(t == 1){
            break;
        }
        for(int j = 0; j <= N-M; j++){
            if(t == 1){
                break;
            }
            int f = 0;
            for(int k = 0; k < M; k++){
                if(t == 1){
                    break;
                }
                for(int l = 0; l < M; l++){
                    if(B[k][l] != A[i+k][j+l]){
                        f = 1;
                        break;
                    }
                }
            }
            if(f == 0){
                t = 1;
            }
        }
    }

    if(t == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    

    return 0;
}
