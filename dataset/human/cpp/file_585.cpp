#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, n; scanf("%d%d%d%d", &r, &g, &b, &n);
    int ans = 0;
    for (int i = 0; i * r <= n; ++i) {
        for (int j = 0; j * b + i * r <= n; ++j) {
            if ((n - j * b - i * r) % g == 0)
                ++ans;
        }
    }
    printf("%d\n", ans);
}
