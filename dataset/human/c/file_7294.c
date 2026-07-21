#include <stdio.h>

int main(void) {
    int H, W, K, F, A[305], B[305], S[305], X[305][305], i, j;
    char s[305][305];
    scanf("%d%d%d", &H, &W, &K);
    for (i=0; i<H; i++) {
        A[i]=0;
        scanf("%s", s[i]);
        for (j=0; j<W; j++) {
            if (s[i][j]=='#') A[i]++;
            X[i][j]=0;
        }
        if (i==0) S[i]=A[i];
        else S[i]=S[i-1]+A[i];
    }
    i=0;
    while (A[i]==0) i++;
    F=i;
    for (i=0; i<H; i++) {
        if (A[i]!=0) {
            for (j=0; j<W; j++) {
                if (j==0) {
                    B[j]=0;
                    if (s[i][j]=='#') B[j]=1;
                }
                else {
                    B[j]=B[j-1];
                    if (s[i][j]=='#') B[j]++;
                }
                if (i==0) {
                    if (B[j]!=0) X[i][j]=B[j];
                    else X[i][j]=1;
                }
                else {
                    if (B[j]!=0) X[i][j]=S[i-1]+B[j];
                    else X[i][j]=S[i-1]+1;
                }
            }
        }
    }
    for (i=F; i<H; i++) {
        if (X[i][0]==0) {
            for (j=0; j<W; j++) X[i][j]=X[i-1][j];
        }
    }
    for (i=F; i>=0; i--) {
        if (X[i][0]==0) {
            for (j=0; j<W; j++) X[i][j]=X[i+1][j];
        }
    }
    for (i=0; i<H; i++) {
        for (j=0; j<W; j++) {
            printf("%d ", X[i][j]);
            if (j!=W-1) printf(" ");
            else if (i!=H-1) printf("\n");
        }
    }
    // printf("[%d]", F);
    return 0;
}
