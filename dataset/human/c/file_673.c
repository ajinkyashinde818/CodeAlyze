#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int flag, i, j, k, M, N;
    scanf("%d%d%*c", &N, &M);
    char A[60][60], B[60][60];
    char tmp1[60], tmp2[60];
    memset(A,0,3600);
    memset(B,0,3600);
    memset(tmp1,0,60);
    memset(tmp2,0,60);
    for (i=0;i<N;i++) {
        scanf("%s", &A[i]);
    }
    for (i=0;i<M;i++) {
        scanf("%s", &B[i]);
    }

    flag = 0;
    if (N == M) {
        for (k=0;k<M;k++) {
            memmove(tmp1, A[k], M);
            memmove(tmp2, B[k], M);
            if (!strcmp(tmp1, tmp2)) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
    } else for (i=0;i<N-M;i++) {
        for (j=0;j<N-M;j++) {
            for (k=0;k<M;k++) {
                memmove(tmp1, A[i+k]+j, M);
                memmove(tmp2, B[k], M);
                if (!strcmp(tmp1, tmp2)) {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
