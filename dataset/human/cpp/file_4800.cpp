#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    if (n >= 10) {
        cout << r;
        return 0;
    }

    int tmp = 100 * (10 - n);

    cout << r+tmp;








    return 0;
}
