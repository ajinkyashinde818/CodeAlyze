#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    int N; cin >> N;
    vector<ll> a(N); for (int i = 0; i < N; i++) cin >> a[i];

    // Cumulative sum
    for (int i = 1; i < N; i++) a[i] += a[i - 1];

    ll ans = INF;
    for (int i = 0; i < N - 1; i++) ans = min(ans, abs(2*a[i] - a[N - 1]));

    cout << ans << endl;
    return 0;
}
