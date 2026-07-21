#include <stdio.h>
int main(void){
    // Your code here!
    int i, j, n, m;
    int dp[100002];
    int flag;
    int a[100002];
    int js = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;

    flag = 0;
    for (j = 0; j < m; j++) {
        if (1 == a[j]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }


    for (i = 2; i <= n; i++) {
        flag = 0;
        for (j = js; j < m; j++) {
            if (i == a[j]) {
                flag = 1;
                js = j + 1;
                break;
            }
        }
        if (flag) {
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    printf("%d\n", dp[n]);

    return 0;
}
