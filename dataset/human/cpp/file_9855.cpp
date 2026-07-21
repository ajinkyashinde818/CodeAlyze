#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    int N;
    string S;
    cin >> N >> S;

    const ll MOD = 1000000007LL;
    ll cnt[26] = {};
    REP(i,S.size()) cnt[S[i] - 'a']++;

    ll ans = 1LL;
    REP(i,26) {
        ans *= (cnt[i] + 1LL);
        ans %= MOD;
    }

    ans = (ans - 1LL + MOD) % MOD;

    cout << ans << endl;

    return 0;
}
