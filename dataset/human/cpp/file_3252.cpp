//written by NewbieChd
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

const int BUF = 1000000;
char buf[BUF], *p1, *p2;
inline char getChar() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF, stdin), p1 == p2) ? EOF : *p1++; }
inline int read() {
    register int f = 0;
    bool b = 1;
    register char c;
    while (!isdigit(c = getChar()))
        if (c == 45)
            b = 0;
    do
        f = f * 10 + (c ^ 48);
    while (isdigit(c = getChar()));
    return b ? f : ~f + 1;
}

const int N = 100003;
const long long inf = 1e18;
int a[N];
long long f[N][2];

int main() {
    register int n = read(), i;
    for (i = 1; i <= n; ++i)
        a[i] = read();
    f[1][0] = a[1], f[1][1] = -inf;
    for (i = 2; i <= n; ++i)
        f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] + a[i]),
        f[i][1] = max(f[i - 1][0] - (a[i - 1] << 1) - a[i], f[i - 1][1] + (a[i - 1] << 1) - a[i]);
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}
