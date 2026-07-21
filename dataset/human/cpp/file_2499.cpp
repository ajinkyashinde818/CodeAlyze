#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
/* #include <regex> */

using namespace std;

/* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */

/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

/* flip A[i] and A[i+1] */

const LL inf = 1e16;
const int maxn = 1e5+5;
/* dp(i,j,k) - at pos(i), j means flip i, k means flip i-1 */
LL A[maxn], n, dp[maxn][2][2];

LL dfs(const int i, const int j, const int k)
{
    if (i == n-1) {
        const LL x = k ? -A[i] : A[i];
        if (j)
            return -x - A[i+1];
        else
            return +x + A[i+1];
    }
    LL& ans = dp[i][j][k];
    if (-1 == ans) {
        ans = -inf;
        const LL x = (k ? -A[i] : A[i]) * (j ? -1 : 1);
        const LL a = dfs(i+1,0,j) + x;
        const LL b = dfs(i+1,1,j) + x;
        ans = max(ans, max(a,b));
    }
    return ans;
}

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n) {
        memset(dp,-1,sizeof(dp));
        FOR(i,1,n+1)
            cin >> A[i];
        const LL ans = max(dfs(1,0,0),dfs(1,1,0));
        cout << ans << endl;
    }
    return 0;
}
