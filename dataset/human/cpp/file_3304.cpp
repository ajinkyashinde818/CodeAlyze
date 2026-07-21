#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first < y.first;});
#define FRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first > y.first;});
#define SSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second < y.second;});
#define SRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second > y.second;});
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define DEBUG true
#define $(x) {if (DEBUG) {cout << #x << " = " << (x) << endl;}}


int main() {
    LL N;
    cin >> N;
    VI A(N);
    REP(i, N) {
        cin >> A[i];
    }
    LL ans = 0;
    LL n_minus = 0;
    LL min_minus = LLONG_MAX, min_plus = LLONG_MAX;

    EACH(x, A) {
        ans += abs(x);
        if (x < 0) {
            n_minus++;
            if (abs(x) < min_minus) {
                min_minus = abs(x);
            }
        } else {
            if (x < min_plus) {
                min_plus = x;
            }
        }
    }
    if (n_minus % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << ans - 2 * min(min_minus, min_plus) << endl;
    }
	
    return 0;
}
