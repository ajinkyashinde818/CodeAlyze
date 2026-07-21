#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;

using namespace std;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 998244353;

template <typename T>
void read(vector<T>& a) {
    for (auto &v : a)
        cin >> v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int n, k;
    cin >> n >> k;
    cout << (n >= 10 ? k : k + 100*(10-n));
}
