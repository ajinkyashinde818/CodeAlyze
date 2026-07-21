#include <iostream>
#include <cstdio>
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int pre[1002];
int res[1002][1002];
int main() {
    int n = read();
    int cnt = 0;
    while (1) {
        cnt++;
        pre[cnt] = pre[cnt - 1] + cnt;
        if (pre[cnt] >= n) break;
    }
    if (pre[cnt] != n) {
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%d\n", cnt + 1);
    int tmp = 0;
    for (int i = 1; i <= cnt + 1; ++i) {
        for (int j = i + 1; j <= cnt + 1; ++j) {
            res[i][j] = ++tmp;
            res[j][i] = tmp;
        }
    }

    for (int i = 1; i <= cnt + 1; ++i) {
        printf("%d ", cnt);
        for (int j = 1; j <= cnt + 1; ++j) {
            if (i == j) continue;
            printf("%d ", res[i][j]);
        }
        puts("");
    }
    return 0;
}
