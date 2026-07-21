#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N], b[N], cnt1[N], cnt2[N], bad[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt1[a[i]]++;
    for (int i = 1; i <= n; i++) cin >> b[i], cnt2[b[i]]++;

    for (int i = 1; i <= n; i++) {
        int pos1 = lower_bound(a, a + n, b[i]) - a, pos2 = pos1 + cnt1[b[i]] - 1;
        if (pos1 <= i and i <= pos2) {
            bad[0]++;
            bad[pos2 - i + 1]--;
            bad[n - (i - pos1)]++;
        } else if (i < pos1) {
            bad[pos1 - i]++;
            bad[pos2 - i + 1]--;
        } else {
            bad[n - (i - pos1)]++;
            bad[n - (i - pos2) + 1]--;
        }
    }

    int rot = -1;
    for (int i = 1; i <= n; i++) {
        bad[i] += bad[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (!bad[i]) {
            rot = i;
            break;
        }
    }

    if (rot == -1) {
        cout << "No\n";
        return 0;
    }

    if (rot != 0)
        rotate(b + 1, b + n + 1 - rot, b + n + 1);

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
    return 0;
}
