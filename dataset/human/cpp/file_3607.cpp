#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll A;
    ll m = 1000000000;
    ll S = 0;
    ll cnt = 0;

    for (ll i = 0; i < N; i++) {
        cin >> A;
        if (A < 0) {
            cnt++;
            A = -1 * A;
        }
        if (m > A) {
            m = A;
        }
        S += A;
    }
    if (cnt % 2 == 0) {
        cout << S << endl;
    } else {
        cout << S - 2 * m << endl;
    }
}
