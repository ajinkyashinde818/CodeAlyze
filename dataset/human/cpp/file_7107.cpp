#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
    cin >> n;
    vector<int> a(n), b(n), counter(n+1, 0);
    vector<int> c(n+1, 0), d(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        counter[a[i]]++;
        c[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        counter[b[i]]++;
        d[b[i]]++;
    }

    for (int i = 0; i <= n; ++i) {
        if(counter[i] > n) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    for (int i = 0; i < n; ++i) {
        c[i+1] += c[i];
        d[i+1] += d[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, c[i] - d[i-1]);
    }

    for (int i = 0; i < n; ++i) {
        cout << b[(i + n - ans) % n] << " ";
    }
    cout << endl;
}
