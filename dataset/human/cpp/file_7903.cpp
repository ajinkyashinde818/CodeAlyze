#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a((size_t) n);
    vector<ll> sum((size_t) n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    ll mind = numeric_limits<ll>::max();
    for (int i = 0; i < n - 1; ++i) {
        mind = min(mind, abs(sum[i + 1] - (sum[n] - sum[i + 1])));
    }

    cout << mind << endl;
}
