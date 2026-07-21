#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    reverse(b.begin(), b.end());
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (b[i] != a[l] && b[i] != b[l]) {
                swap(b[i], b[l++]);
            }
            else if (b[i] != a[r] && b[i] != b[r]) {
                swap(b[i], b[r--]);
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i : b) {
        cout << i << " ";
    }
    return 0;
}
