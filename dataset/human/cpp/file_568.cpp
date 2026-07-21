#include <bits/stdc++.h>
using namespace std;

/*
Returns the gcd of a, b
g = ax+by
Say a = qb+r
Then gcd(a, b) = gcd(b, r)
g = X*b + Y*r = X*b + Y*(a - qb) = a * Y + b * (X - q*Y)
*/
int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int X, Y;
    int g = egcd(b, a % b, X, Y);
    x = Y;
    y = X - (a / b) * Y;
    return g;
}

int inv(int a, int m) {
    int g, x, y;
    g = egcd(a, m, x, y);
    if (g != 1) return -1;
    x %= m;
    if (x < 0) x += m;
    return x;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    // freopen("data.txt", "r", stdin);
    int r, g, b, n;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    const int d = gcd(g, b);
    g /= d;
    b /= d;
    int ans = 0;
    for (int nr = 0; nr * r <= n; ++nr) {
        int m = n - r * nr;
        // gx+by = m
        if (m % d != 0) continue;
        m /= d;
        int x = inv(g, b) * m % b;
        if (g * x <= m) {
            ans += 1 + (m / g - x) / b;
        }
        // g(x+kb) <= m, k <= (m/g-x)/b
    }
    printf("%d\n", ans);
}
