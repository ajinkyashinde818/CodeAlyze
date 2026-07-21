#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 1e5 + 10, MOD = 1e9 + 7;
char s[2*N];
bool a[2*N];
vector<int> le, ri;
bool flag = 1;

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s",s);
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'B') a[i] = 1;
        else a[i] = 0;
    }
    int inv = 0;
    for (int i = 0; i < 2 * n; i++) {
        if ((inv ^ a[i]) == 1) {
            le.push_back(i);
        } else {
            ri.push_back(i);
        }
        inv ^= 1;
    }
    flag = le.size() == ri.size();
    if (flag) {
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans = 1LL * ans * (i + 1 - (upper_bound(ri.begin(), ri.end(), le[i]) - ri.begin())) % MOD;
        }
        for (int i = 1; i <= n; i++) {
            ans = 1LL * ans * i % MOD;
        }
        printf("%d\n", ans);
    } else puts("0");
    return 0;
}
