#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    reverse(b.begin(), b.end());
    int c = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            c = a[i];
            break;
        }
    }
    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == c and b[i] == c) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != c and b[i] != c and l <= r) {
            swap(b[i], b[l]);
            ++l;
        }
    }
    if (l <= r) {
        cout << "No" << "\n";
        return 0;
    }
    cout << "Yes" << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}
