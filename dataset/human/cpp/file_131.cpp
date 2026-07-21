#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    int a[3], n, ans = 0;
    cin >> a[0] >> a[1] >> a[2] >> n;

    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j) {
            int rest = (n - a[0]*i - a[1]*j);
            if(rest < 0 || rest % a[2]) continue;
            ++ans;
        }
    }

    cout << ans << endl;
}
