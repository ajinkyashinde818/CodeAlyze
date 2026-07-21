#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll k = 0, ans = 0, m = 1'000'000'000;
    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        if (A < 0) {
            k++;
            A = -A;
        }
        ans += A;
        m = min(m, A);
    }
    if (k % 2 != 0) {
        ans -= m + m;
    }
    cout << ans << endl;
}
