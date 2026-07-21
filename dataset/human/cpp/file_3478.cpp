#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    int cntNeg = 0;
    for (auto &x : A) {
        cin >> x;
        if (x < 0) {
            cntNeg++;
            x *= -1;
        }
    }
    sort(A.begin(), A.end());
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        if (i < cntNeg % 2) {
            sum -= A.at(i);
        } else {
            sum += A.at(i);
        }
    }
    cout << sum << endl;

    return 0;
}
