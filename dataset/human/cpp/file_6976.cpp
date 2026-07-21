#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> count_a(n+1, 0), count_b(n+1, 0);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        ++count_a[a[i]];
    }
    for(int i=0;i<n;++i) {
        cin >> b[i];
        ++count_b[b[i]];
    }

    for(int i=1;i<=n;++i) {
        if(count_b[i] > n - count_a[i]) {
            cout << "No" << endl;
            return 0;
        }
        count_a[i] += count_a[i-1];
        count_b[i] += count_b[i-1];
    }

    int x = 0;
    for(int i=1;i<=n;++i) {
        x = max(x, count_a[i] - count_b[i-1]);
    }

    cout << "Yes\n";
    for(int i=0;i<n;++i) {
        if(i) cout << " ";
        cout << b[(i-x+n) % n];
    }
    cout << "\n";
}
