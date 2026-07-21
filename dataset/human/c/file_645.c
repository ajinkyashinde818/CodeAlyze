// ABC054 B - Template Matching
#include <stdio.h>
#include <string.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    char A[50][51];
    char B[50][51];
    char joinA[2501] = {'\0'};
    char joinB[2501] = {'\0'};
    int i;
    for (i = 0; i < N; i++) {
        scanf("%s", A[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%s", B[i]);
    }

    for (i = 0; i < M; i++) {
        strcat(joinB, B[i]);
    }
    int x, y;
    for (y = 0; y < (N - M + 1); y++) {
        for (x = 0; x < (N - M + 1); x++) {
            if (A[y][x] == joinB[0]) {
                // joinAを作る
                for (i = 0; i < M; i++) {
                    strncat(joinA, &A[y + i][x], M);
                }
                // printf("joinA:%s\n",joinA);
                // joinA=joinBならYes
                if (strcmp(joinA, joinB) == 0) {
                    printf("Yes\n");
                    return 0;
                }
                joinA[0] = '\0';
            }
        }
    }

    printf("No\n");
    return 0;

}
