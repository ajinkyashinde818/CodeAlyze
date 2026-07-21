#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int n, a[100][101];
int dp[101][101][101];

int main(void){
    int x, y, z;
    scanf("%d", &n);
    for(x = 0; x < n; x++){
        a[x][0] = 0;
        for(y = 1; y <= n; y++){
            scanf("%d", &a[x][y]);
            a[x][y] += a[x][y-1];
        }
    }
    int max_val = a[0][1];
    for(x = 0; x < n; x++){
        for(y = x+1; y <= n; y++){
            dp[0][x][y] = a[0][y] - a[0][x];
            max_val = max(max_val, dp[0][x][y]);
        }
    }
    for(x = 1; x < n; x++){
        for(y = 0; y < n; y++){
            for(z = y+1; z <= n; z++){
                int s = a[x][z] - a[x][y];
                dp[x][y][z] = max(s, s+dp[x-1][y][z]);
                max_val = max(max_val, dp[x][y][z]);
            }
        }
    }
    printf("%d\n", max_val);
    return 0;
}
