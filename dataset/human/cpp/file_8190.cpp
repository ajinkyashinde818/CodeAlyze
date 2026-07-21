#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 2.0e5 + 100;
ll a[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }

    ll min_diff = 1.0e18;
    ll now = 0;
    for (int i = 0; i < N - 1; i++) {
        now += a[i];
        min_diff = min(min_diff, abs(now - (sum - now)));
    }

    cout << min_diff << endl;

    return 0;
}
