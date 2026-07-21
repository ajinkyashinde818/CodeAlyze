#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1000000007;
const int INF = 1000000000;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, R;
    cin >> N >> R;
    if (N >= 10) cout << R << endl;
    else cout << R + 100 * (10 - N) << endl;
}
