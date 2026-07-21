#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const double EPS = 1e-9;
FILE *fp;

void init();
void last();

//#define MYLOCAL

const int MAX = 200010;
int n, m;
bool used[MAX];

void init() {
#ifdef MYLOCAL
    if ((fp = freopen("/Users/sekiya9311/Documents/comp_programming/comp_programming/in.txt", "r", stdin)) == NULL) {
        assert(false);
    }
#endif
    memset(used, false, sizeof(used));
    scanf("%d%d", &n, &m);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        st.push(i + 1);
    }
    for (int i = 0; i < m; i++) {
        int e;
        scanf("%d", &e);
        st.push(e);
    }
    while (!st.empty()) {
        if (used[st.top()]) {
            st.pop();
            continue;
        }
        used[st.top()] = true;
        printf("%d\n", st.top());
        st.pop();
    }
    last();
}

void last() {
#ifdef MYLOCAL
    fclose(fp);
#endif
    exit(0);
}

void solve(int n) {
    
    last();
}

signed main(void) {
    LL n, m, p, a, b, c, x, y, z, q;
    string s;
    bool f = false;
    init();
    while (cin >> n, n) {
        solve(n);
        //return 0;
    }
    last();
}
