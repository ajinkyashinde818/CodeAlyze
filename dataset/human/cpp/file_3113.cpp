//
// Created by Hideaki Imamura on 2019-06-06.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> A, absA;
ll n_minus = 0;

int main() {
    cin >> N;
    A.resize(N);
    absA.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        absA[i] = (ll)abs(A[i]);
        if (A[i] <= 0) n_minus++;
    }

    ll ans = accumulate(absA.begin(), absA.end(), 0LL);
    if (n_minus % 2) ans -= 2 * *min_element(absA.begin(), absA.end());
    cout << ans << endl;
    return 0;
}
