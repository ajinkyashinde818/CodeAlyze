#include <stdio.h>
#include <math.h>
int A[80][80];
int dp[80][80][8001];
int main()
{
    int H, W, res;
    scanf(" %d %d", &H, &W);
    for (int i = 0; i < H; ++i) 
        for (int j = 0; j < W; ++j)
            scanf(" %d", &A[i][j]);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            int c;
            scanf(" %d", &c);
            A[i][j] = abs(A[i][j]-c);
        }

    dp[0][0][A[0][0]] = 1;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            for (int k = 0; k <= 8000; ++k) {
                if (dp[i][j][k]) {
                    if (i != H - 1) {
                        int c = k+A[i+1][j];
                        if (c <= 8000) dp[i+1][j][c] = 1;
                        dp[i+1][j][abs(k-A[i+1][j])] = 1;
                    }
                    if (j != W - 1) {
                        int c = k+A[i][j+1];
                        if (c <= 8000) dp[i][j+1][c] = 1;
                        dp[i][j+1][abs(k-A[i][j+1])] = 1;
                    }
                }
            }
    for (res = 0; res <= 8000; ++res) if (dp[H-1][W-1][res]) break;
    printf("%d\n", res);
    return 0;
}
