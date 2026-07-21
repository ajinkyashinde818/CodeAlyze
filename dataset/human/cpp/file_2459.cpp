/* #region Head */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
using vll = vc<ll>;
using vvll = vvc<ll>;
using vld = vc<ld>;
using vvld = vvc<ld>;
using vs = vc<string>;
using vvs = vvc<string>;
template <class T, class U>
using um = unordered_map<T, U>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqa = priority_queue<T, vc<T>, greater<T>>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())
#define PERM(c)   \
    sort(ALL(c)); \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
#define UNIQ(v) v.erase(unique(ALL(v)), v.end());

#define endl '\n'
#define sqrt sqrtl

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr ll MOD = 1'000'000'007LL; // 1e9 + 7
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.14159265358979323846;

// vector 入力
template <typename T>
istream &operator>>(istream &is, vc<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

// vector 出力 (for dump)
template <typename T>
ostream &operator<<(ostream &os, vc<T> &vec)
{
    ll len = SIZE(vec);
    os << "{";
    for (int i = 0; i < len; i++)
        os << vec[i] << (i == len - 1 ? "" : ", ");
    os << "}";
    return os;
}

// vector 出力 (inline)
template <typename T>
ostream &operator>>(ostream &os, vc<T> &vec)
{
    ll len = SIZE(vec);
    for (int i = 0; i < len; i++)
        os << vec[i] << (i == len - 1 ? "\n" : " ");
    return os;
}

// pair 入力
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &pair_var)
{
    is >> pair_var.first >> pair_var.second;
    return is;
}

// pair 出力
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var)
{
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// map 出力
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var)
{
    os << "{";
    REPI(itr, map_var)
    {
        os << *itr;
        itr++;
        if (itr != map_var.end())
            os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// um 出力
template <typename T, typename U>
ostream &operator<<(ostream &os, um<T, U> &map_var)
{
    os << "{";
    REPI(itr, map_var)
    {
        os << *itr;
        auto itrcp = itr;
        itrcp++;
        if (itrcp != map_var.end())
            os << ", ";
    }
    os << "}";
    return os;
}

// set 出力
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var)
{
    os << "{";
    REPI(itr, set_var)
    {
        os << *itr;
        itr++;
        if (itr != set_var.end())
            os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// dump
#define DUMPOUT cerr
void dump_func()
{
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) > 0)
    {
        DUMPOUT << ", ";
    }
    dump_func(move(tail)...);
}

// chmax (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>>
bool chmax(T &xmax, const U &x, Comp comp = {})
{
    if (comp(xmax, x))
    {
        xmax = x;
        return true;
    }
    return false;
}

// chmin (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>>
bool chmin(T &xmin, const U &x, Comp comp = {})
{
    if (comp(x, xmin))
    {
        xmin = x;
        return true;
    }
    return false;
}

// ローカル用
#define DEBUG_

#ifdef DEBUG_
#define DEB
#define dump(...)                                                       \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                     \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" \
            << endl                                                     \
            << "    ",                                                  \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct AtCoderInitialize
{
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    AtCoderInitialize()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH)
            cout << unitbuf;
    }
} ATCODER_INITIALIZE;

string yes = "Yes", no = "No";
// string yes = "YES", no = "NO";

/* #endregion */

/**
Problem
 */
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;

    // 負数が偶数個だった場合，全ての数を非負整数にできるので，それが答え
    // 負数がき数個だった場合，どれか絶対値が一番小さいものを負数，それ以外を非負整数とする
    ll absmin = INF;
    ll abssum = 0;
    ll cnt_negative = 0;
    REP(i, 0, n)
    {
        if (a[i] < 0)
        {
            cnt_negative++;
            chmin(absmin, -a[i]);
            abssum -= a[i];
        }
        else
        {
            chmin(absmin, a[i]);
            abssum += a[i];
        }
    }
    if (cnt_negative % 2 == 0)
    {
        cout << abssum << endl;
    }
    else
    {
        cout << (abssum - 2 * absmin) << endl;
    }
}

/**
 * エントリポイント．
 * @return 0.
 */
int main()
{
    solve();
    return 0;
}
