#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;

constexpr ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s; 
    cin >> s;

    vector<int> cnt(26, 0);
    for (auto &&c: s) ++cnt[c-'a'];

    ll ans = 1;
    for (auto &&e: cnt) {
        ans *= (e+1);
        ans %= mod;
    }

    cout << ans-1 << endl;

    return 0;
}
