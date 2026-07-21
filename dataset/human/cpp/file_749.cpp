//written by NewbieChd
#include <cstdio>
#include <cctype>
using namespace std;

const int BUF = 1000000;
char buf[BUF], *p1, *p2;
inline char getChar() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF, stdin), p1 == p2) ? EOF : *p1++; }
inline int read() {
    register int f = 0;
    register char c;
    while (!isdigit(c = getChar())) {}
    do
        f = f * 10 + (c ^ 48);
    while (isdigit(c = getChar()));
    return f;
}

const int N = 3007;
long long dp[N];

int main() {
    int r = read(), g = read(), b = read(), n = read(), i, j;
    dp[0] = 1;
    for (i = 1; i <= n; ++i)
        if (i >= r)
            dp[i] += dp[i - r];
    for (i = 1; i <= n; ++i)
        if (i >= g)
            dp[i] += dp[i - g];
    for (i = 1; i <= n; ++i)
        if (i >= b)
            dp[i] += dp[i - b];
    printf("%d\n", dp[n]);
    return 0;
}
