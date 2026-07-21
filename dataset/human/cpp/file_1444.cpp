#include <cstdio>
#include <cstdlib>

#include <vector>
#include <iostream>
#include <algorithm>
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;
const int P = 1000000007;
const int INF = 1000000007;
const double eps = 1e-6;
using namespace std;
inline int getint() {
    int r = 0; bool b = true; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') b = false; c = getchar(); }
    while (c >= '0' && c <= '9') { r = (r<<1)+(r<<3) + c - '0'; c = getchar(); }
    return b ? r : -r;
}
vector<int> v[450];
int n, k = -1;
int main() {
    n = getint();
    for (int i = 1; i * (i - 1) <= n * 2; ++i) {
        if (i * (i - 1) == n * 2) {
            k = i;
            break;
        }
    }
    if (k == -1) puts("No");
    else {
        int tot = 0;
        for (int i = 1; i < k; ++i)
            for (int j = i + 1; j <= k; ++j) {
                ++tot;
                v[i].push_back(tot);
                v[j].push_back(tot);
            }
        printf("Yes\n%d\n", k);
        for (int i = 1; i <= k; ++i) {
            printf("%d", k - 1);
            for (auto &j : v[i])
                printf(" %d", j);
            putchar('\n');
        }
    }
}
