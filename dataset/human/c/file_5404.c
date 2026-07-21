#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int N, M, X;
    int CA[12][13];
    int min = 2147483647; // 最小価格

    scanf("%d %d %d", &N, &M, &X);
    for(int i = 0; i < N; i++) {
        scanf("%d", &CA[i][0]);
        for(int j = 1; j <= M; j++) {
            scanf("%d", &CA[i][j]);
        }
    }

    for(int i = 1; i <= pow(2, N); i++) {
        int S = 0;          // 合計価格
        int A[12] = {0};    // 理解度
        int OK = true;
        
        for(int j = 0; j < N; j++) {
            if((i & (int)pow(2,j)) != 0) {
                S += CA[j][0];
                for(int k = 1; k <= M; k++) {
                    A[k-1] += CA[j][k];
                }
            }
        }

        for(int k = 0; k < M; k++) {
            if(A[k] < X) {
                OK = false;
            }
        }

        if(OK == false) {
            continue;
        }

        if(min > S) {
            min = S;
        }
    }

    if(min == 2147483647) {
        printf("-1\n");
    }
    else {
        printf("%d\n", min);
    }

    return 0;
}
