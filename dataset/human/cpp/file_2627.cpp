#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
#include <climits>
#include <time.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}
ll ketasum(ll n) { //桁の数字全ての和を返す 例: 112 -> 4
	ll sum=0;
	if (n<0) return 0;
	while (n>0) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

typedef pair<ll, ll> pair_t;

bool comp(const pair_t &a, const pair_t &b) {
        return a.first < b.first;
}

void sort2vectors(vector<ll> &av, vector<ll> &bv)
{ // ふたつの配列をまとめてそーと A[2,1] B[3,4] -> 1,4 2,3
        ll n = av.size();
        vector<pair_t> p(n);
        vector<ll> av2(n), bv2(n);
        for (ll i = 0; i < n; i++)
                p[i] = make_pair(av[i], bv[i]);
        sort(p.begin(), p.end(), comp);
        for (ll i = 0; i < n; i++) {
                av2[i] = p[i].first;
                bv2[i] = p[i].second;
        }
        av = av2;
        bv = bv2;
}
ll facctorialMethod(ll k){ //階乗
	ll s;
	if(k > 1){
		s = k*facctorialMethod(k-1);
	} else {
		s = 1;
	}
	return s;
}

map< int64_t, ll > prime_factor(int64_t n) {
  map< int64_t, ll > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
// dp[i] := 長さが i の増加部分列として最後尾の要素のとりうる最小値
template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    const T INF = 1<<30; // to be set appropriately
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
void foreach_permutation(ll n, std::function<void(ll *)> f) {
  ll indexes[n];
  for (ll i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

long double dist(ll x, ll y, ll x2, ll y2){
	return sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
}
ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
const ll MOD = 1000000007;
const ll INF = 1e10;
const int MAX = 10000000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// Sparse Table
template<class MeetSemiLattice> struct SparseTable {
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable() { }
    SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    MeetSemiLattice get(int a, int b) {
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};


// Suffix Array ( Manber&Myers: O(n (logn)^2) )
struct SuffixArray {
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int& operator [] (int i) {return sa[i];}
    
    SuffixArray(const string& str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string& str_) { str = str_; buildSA(); calcLCP(); }
    
    // build SA
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }
    vector<int> rsa;
    SparseTable<int> st;
    void calcLCP() {
        int n = (int)str.size();
        rsa.resize(n+1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n+1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        st.init(lcp);
    }
    
    // calc lcp
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
        return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
};

template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};
using RH = RollingHash< 1000000007 >;
void UFinit(ll n);
ll UFfind(ll x);
void UFunite(ll x, ll y);
bool UFsame(ll x, ll y);
ll MAX_N; //Union-Find木使う時はcinする

/******変数定義start(vectorはresizeしようね)******/
ll N;
vl A;
/******変数定義end********************************/
void solve(){
    cin >> N;
    A.resize(N);
    REP(i, N){
        cin >> A[i];
    }
    vector< vector<ll> > dp(N+1, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = -INF;
    REP(i, N){
        dp[i+1][0] = max(dp[i][0]+A[i], dp[i][1]-A[i]);
        dp[i+1][1] = max(dp[i][0]-A[i], dp[i][1]+A[i]);
    }
    cout << dp[N][0] << endl;
}

vl UFpar(MAX_N);
vl UFrank(MAX_N);
void UFinit(ll n){
    REP(i, n){
        UFpar[i] = i;
        UFrank[i] = 0;
    }
}
ll UFfind(ll x){
    if(UFpar[x] == x){
        return x;
    }else{
        return UFpar[x] = UFfind(UFpar[x]);
    }
}
void UFunite(ll x, ll y){
    x = UFfind(x);
    y = UFfind(y);
    if(x == y){return;}
    if(UFrank[x] < UFrank[y]){
        UFpar[x] = y;
    }else{
        UFpar[y] = x;
        if(UFrank[x] == UFrank[y]){UFrank[x]++;}
    }
}
bool UFsame(ll x, ll y){
    return UFfind(x) == UFfind(y);
}

int main(){

    //clock_t start = clock();

    cout << std::fixed << std::setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    //clock_t end = clock();
    //const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    //printf("time %lf[ms]\n", time);
}
