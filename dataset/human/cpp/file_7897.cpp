//https://atcoder.jp/contests/abc067/tasks/arc078_a
//C - Splitting Pile
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> a;

int main() {
    cin >> N;
    a.resize(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%Ld", &a[i]);
        sum += a[i];
    }
    ll ans = 1e10;
    ll x = 0;
    for (int i = 0; i < N; i++) {
        x += a[i];
        if (i != N-1) ans = min(ans, abs(sum - 2*x));
    }
    cout << ans << endl;
}
