#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define TR ","
#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

ll LCM(ll x, ll y) {
    return x / GCD(x, y) * y;
}

ll wazu = 1000000007;

ll inv(ll x) {
    if (x == 1) { return 1; }
    if (x == 0) { return 0; }
    else {
        ll a = (wazu - inv(wazu % x) * (wazu / x)) % wazu;
        if (a >= 0) { return a; }
        else { return wazu + a; }
    }
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<string> A(N);
    vector<string> B(M);

    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<vector<char> > P(N,vector<char>(N));
    vector<vector<char> > Q(M,vector<char>(M));

    rep(i, N) {
        rep(j, N) {
            P[i][j] = A[i][j];
        }
    }

    rep(i, M) {
        rep(j, M) {
            Q[i][j] = B[i][j];
        }
    }

    int kk = 0;

    rep(x, N - M + 1) {
        rep(y, N - M + 1) {
            int k = 0;
            rep(i, M) {
                rep(j, M) {
                    if (Q[i][j] == P[i + x][j + y]) { ++k; }
                }
            }
            if (k == M * M) {
                ++kk; }
        }
    }

    if (kk > 0) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }

}
