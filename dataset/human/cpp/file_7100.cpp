/* #region Head */

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vc<vc<T>>;
using vll = vc<ll>;
using vvll = vvc<ll>;
using vld = vc<ld>;
using vvld = vvc<ld>;
using vs = vc<string>;
using vvs = vvc<string>;
template <class T, class U> using um = unordered_map<T, U>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqa = priority_queue<T, vc<T>, greater<T>>;
template <class T> using us = unordered_set<T>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())
#define PERM(c)                                                                                                        \
    sort(ALL(c));                                                                                                      \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
#define UNIQ(v) v.erase(unique(ALL(v)), v.end());

#define endl '\n'
#define sqrt sqrtl
#define floor floorl
#define log2 log2l

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr int IINF = 1'000'000'007LL;
constexpr ll MOD = 1'000'000'007LL; // 1e9 + 7
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.14159265358979323846;

template <typename T> istream &operator>>(istream &is, vc<T> &vec) { // vector 入力
    for (T &x : vec) is >> x;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, vc<T> &vec) { // vector 出力 (for dump)
    os << "{";
    REP(i, 0, SIZE(vec)) os << vec[i] << (i == i_len - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T> ostream &operator>>(ostream &os, vc<T> &vec) { // vector 出力 (inline)
    REP(i, 0, SIZE(vec)) os << vec[i] << (i == i_len - 1 ? "\n" : " ");
    return os;
}

template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &pair_var) { // pair 入力
    is >> pair_var.first >> pair_var.second;
    return is;
}
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) { // pair 出力
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// map, um, set, us 出力
template <class T> ostream &out_iter(ostream &os, T &map_var) {
    os << "{";
    REPI(itr, map_var) {
        os << *itr;
        auto itrcp = itr;
        if (++itrcp != map_var.end()) os << ", ";
    }
    return os << "}";
}
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) { return out_iter(os, map_var); }
template <typename T, typename U> ostream &operator<<(ostream &os, um<T, U> &map_var) {
    os << "{";
    REPI(itr, map_var) {
        auto [key, value] = *itr;
        os << "(" << key << ", " << value << ")";
        auto itrcp = itr;
        if (++itrcp != map_var.end()) os << ", ";
    }
    os << "}";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) { return out_iter(os, set_var); }
template <typename T> ostream &operator<<(ostream &os, us<T> &set_var) { return out_iter(os, set_var); }
template <typename T> ostream &operator<<(ostream &os, pq<T> &pq_var) {
    pq<T> pq_cp(pq_var);
    os << "{";
    if (!pq_cp.empty()) {
        os << pq_cp.top(), pq_cp.pop();
        while (!pq_cp.empty()) os << ", " << pq_cp.top(), pq_cp.pop();
    }
    return os << "}";
}

// dump
#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) DUMPOUT << ", ";
    dump_func(move(tail)...);
}

// chmax (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmax(T &xmax, const U &x, Comp comp = {}) {
    if (comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

// chmin (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>> bool chmin(T &xmin, const U &x, Comp comp = {}) {
    if (comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

// ローカル用
#define DEBUG_

#ifdef DEBUG_
#define DEB
#define dump(...)                                                                                                      \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                                                                    \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl                                        \
            << "    ",                                                                                                 \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

#define VAR(type, ...)                                                                                                 \
    type __VA_ARGS__;                                                                                                  \
    cin >> __VA_ARGS__;

template <typename T> istream &operator,(istream &is, T &rhs) { return is >> rhs; }
template <typename T> ostream &operator,(ostream &os, const T &rhs) { return os << ' ' << rhs; }

struct AtCoderInitialize {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;
    AtCoderInitialize() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH) cout << unitbuf;
    }
} ATCODER_INITIALIZE;

void Yn(bool p) { cout << (p ? "Yes" : "No") << endl; }
void YN(bool p) { cout << (p ? "YES" : "NO") << endl; }

/* #endregion */

/* #region rand */

// [lb, ub] の値を等確率で発生させる
class Rand {
    using dist_type = std::uniform_int_distribution<>;

    ll _lb;
    ll _ub;
    std::random_device rd; // Will be used to obtain a seed for the random number engine
    std::mt19937 gen;      // Standard mersenne_twister_engine seeded with rd()
    dist_type dis;

  public:
    Rand(ll lb, ll ub) : _lb(lb), _ub(ub), rd(), gen(rd()), dis(lb, ub) {}
    inline int operator()() noexcept { return dis(gen); }
    inline void set_param(ll lb, ll ub) noexcept {
        if (lb == _lb && ub == _ub) return;
        dist_type::param_type param(lb, ub);
        dis.param(param);
    }
};

// [lb, ub) の値を等確率で発生させる
class RandDouble {
    std::random_device seed_gen;
    std::default_random_engine engine;
    std::uniform_real_distribution<> dist;

  public:
    RandDouble(double lb, double ub) : seed_gen(), engine(seed_gen()), dist(lb, ub) {}
    inline double operator()() noexcept { return dist(engine); }
};

/* #endregion */

/* #region Anneal */

// 誰でもできる焼きなまし法 - gasin’s blog http://gasin.hatenadiary.jp/entry/2019/09/03/162613
struct Anneal {
    using clk = chrono::system_clock;

    double timespan_ms; // 焼きなます時間
    double start_temp;  // 開始温度 (一回の遷移で動きうるスコア幅の最大値程度)
    double end_temp;    // 終了温度 (一回の遷移で動きうるスコア幅の最小値程度)
    RandDouble rd;
    clk::time_point start_time;
    double ms_elapsed;

    // コンストラクタ
    Anneal(double timespan_ms, double start_temp, double end_temp)
        : timespan_ms(timespan_ms), start_temp(start_temp), end_temp(end_temp), rd(0, 1), start_time(clk::now()),
          ms_elapsed(0) {}

    // スコアの差分から，遷移するかどうかを確率的に決定して返す
    inline bool transit(double dif) noexcept {
        clk::time_point cur_time = clk::now();
        ms_elapsed =
            static_cast<double>(chrono::duration_cast<chrono::microseconds>(cur_time - start_time).count() / 1000.0);
        // 温度関数
        double temperature = start_temp + (end_temp - start_temp) * (ms_elapsed / timespan_ms);
        // 遷移確率関数(最大化の場合)
        double prob = exp((double)dif / temperature);

        // cout << dif, prob, '\n';
        return prob > rd();
    }

    // transit の山登り版
    inline bool climb(double dif) noexcept {
        clk::time_point cur_time = clk::now();
        ms_elapsed =
            static_cast<double>(chrono::duration_cast<chrono::microseconds>(cur_time - start_time).count() / 1000.0);
        return dif > 0;
    }

    // 時間切れかどうかを返す
    inline bool runnable() noexcept { return ms_elapsed < timespan_ms; }
};

/* #endregion */

/* #region SeparatedIndices */

// 冒頭 k 個が pred を充足するインデックス，それ以外は pred を充足しないインデックス，
// となるように，インデックスの順列を管理するクラス
class SeparatedIndices {
    using IntPredicate = function<bool(int)>;
    using idx_key = int; // 内部キー
    using idx_val = int;

    int n;               // 要素数
    vc<idx_val> indices; // インデックスの順列，0..(n-1)
    vc<idx_key> val2key; // val2key[i] := 上の順列中の何番目に値 i が入っているか
    int k;               // 冒頭 k 個が pred を充足するインデックスとなる
    IntPredicate pred;

    // i 番目のインデックスと j 番目のインデックスを単に swap する
    void _swap(const idx_key i, const idx_key j) {
        idx_val iv = indices[i], jv = indices[j];
        swap(indices[i], indices[j]);
        swap(val2key[iv], val2key[jv]);
    }

  public:
    // コンストラクタ
    SeparatedIndices(const int n, IntPredicate pred) : n(n), indices(n), val2key(n), k(0), pred(pred) { init(); }

    // インデックス順列の初期化を行う
    void init() noexcept {
        // k = 0;
        iota(ALL(indices), 0);
        iota(ALL(val2key), 0);
        for (idx_key i = n - 1; i >= k;) { // 後ろから見ていく
            if (pred(indices[i])) {
                _swap(i, k++); // 条件を満たすインデックスは前へ持っていく
            } else {
                --i;
            }
        }
    }

    // i 番目になっているインデックスを返す
    const idx_val &operator[](idx_key i) const noexcept { return indices[i]; }

    // pred を充足するインデックスの個数を返す
    int count() const noexcept { return k; }

    // i 番目のインデックスが pred を充足するかどうかの情報を更新する
    void update(idx_key i) noexcept {
        bool cond = pred(indices[i]);
        if (i < k) {
            if (!cond) _swap(i, --k); // 充足しないなら，前の区画から追い出す
        } else {
            if (cond) _swap(i, k++); // 充足するなら，前の区画の末尾に追加する
        }
    }

    // i, j 番目のインデックスが pred を充足するかどうかの情報を更新する
    void update(idx_key i, idx_key j) noexcept {
        if (i < k) {
            if (!pred(indices[i])) {
                _swap(i, --k); // 充足しないなら，前の区画から追い出す
                if (j == k) j = i; // 見ようと思っていた j が上記操作で i にすげ替えられていたら，捕捉し直す
            }
        } else {
            if (pred(indices[i])) {
                _swap(i, k); // 充足するなら，前の区画の末尾に追加する
                if (j == k++) j = i; // 見ようと思っていた j が上記操作で i にすげ替えられていたら，捕捉し直す
            }
        }
        update(j);
    }

    // インデックス iv, jv に対応する要素が pred を充足するかどうかの情報を更新する
    void update_val(idx_val iv, idx_val jv) noexcept { update(val2key[iv], val2key[jv]); }
};

// 「少なくとも片方は pred を充足するように，相異なる2つのインデックスを選ぶ」ためのクラス．
// 動的に管理しつつ変更や取り出しを O(1) で行う．
class SeparatedIndicesSwapper {
    using IntPredicate = function<bool(int)>;
    using idx_key = int; // 内部キー
    using idx_val = int;

    SeparatedIndices indices;
    int cnt;

    Rand rand_satisfied; // pred を充足する範囲内の内部インデックスキーを得るためのインスタンス
    Rand rand_all;

  public:
    // コンストラクタ
    SeparatedIndicesSwapper(const int n, IntPredicate pred)
        : indices(n, pred), cnt(indices.count()), rand_satisfied(0, 0), rand_all(0, n - 2) {
        if (cnt > 0) rand_satisfied.set_param(0, cnt - 1);
    }

    // 相異なる2つのインデックスを返す．
    // 少なくとも1つ目は pred を充足するインデックスとなっている．
    pair<idx_val, idx_val> get() noexcept {
        assert(cnt > 0);
        idx_key idx_satisfied = rand_satisfied();
        idx_key idx_all = rand_all();
        if (idx_all >= idx_satisfied) idx_all++; // 重複回避用
        return {indices[idx_satisfied], indices[idx_all]};
    }

    // インデックス iv, jv に対応する要素が pred を充足するかどうかの情報を更新する
    void update(idx_val iv, idx_val jv) noexcept {
        indices.update_val(iv, jv);
        cnt = indices.count();
        if (cnt > 0) rand_satisfied.set_param(0, cnt - 1);
    }

    int count() const noexcept { return cnt; }
};

/* #endregion */

template <typename T> vc<pair<T, ll>> vec_continuous_cnts(vc<T> &v) {
    ll sz = SIZE(v);
    vc<pair<T, ll>> ret;
    if (sz == 0) return ret;
    ll cnt = 1;
    REP(i, 1, sz) {
        if (v[i] == v[i - 1])
            ++cnt;
        else {
            ret.emplace_back(v[i - 1], cnt);
            cnt = 1;
        }
    }
    ret.emplace_back(v[sz - 1], cnt);
    return ret;
}

// Problem
void solve() {
    ll n;
    cin >> n;
    vll a(n), b(n);
    cin >> a, b;

    { // ダメな場合を先に弾く
        vc<pll> cnts_a = vec_continuous_cnts(a);
        vc<pll> cnts_b = vec_continuous_cnts(b);

        vll acc_a(n + 1, 0), acc_b(n + 1, 0); // 値→その値以下の総数
        for (auto [num, cnt] : cnts_a) {
            acc_a[num] = cnt;
        }
        for (auto [num, cnt] : cnts_b) {
            acc_b[num] = cnt;
        }
        REPM(i, 1, n) if (acc_a[i] + acc_b[i] > n) {
            Yn(false);
            return;
        }
    }

    reverse(ALL(b));
    ll cnt = 0;
    REP(i, 0, n) if (a[i] == b[i]) cnt++;
    if (cnt == 0) {
        Yn(true);
        cout >> b;
        return;
    }

    if (cnt * 2 > n) {
        Yn(false);
        return;
    }
    ll score = n - cnt;

    auto pred = [&](int i) -> bool { return a[i] == b[i]; };
    SeparatedIndicesSwapper indices(n, pred);

    double timespan_ms = 1950.0; // 焼きなます時間
    double start_temp = 1.0;     // 開始温度 (一回の遷移で動きうるスコア幅の最大値程度);
    double end_temp = 0.01;      // 終了温度 (一回の遷移で動きうるスコア幅の最小値程度);
    Anneal anneal(timespan_ms, start_temp, end_temp);

    while (anneal.runnable()) {
        auto [idx_ng, idx_all] = indices.get();

        // 仮で swap してみる
        swap(b[idx_ng], b[idx_all]); // これにより，pred の戻り値が変わる
        indices.update(idx_ng, idx_all);

        int score_new = n - indices.count();
        int diff = score_new - score;

        // 焼き鈍し: transit(dif)
        // 山登り:  climb(dif)
        if (anneal.transit(diff)) {
            score = score_new;
            if (score == n) break;
        } else {
            // 巻き戻す
            swap(b[idx_ng], b[idx_all]); // これにより，pred の戻り値が変わる
            indices.update(idx_ng, idx_all);
        }
    }

    if (score < n) {
        Yn(false);
        return;
    }
    Yn(true);
    cout >> b;
}

// entry point
int main() {
    solve();
    return 0;
}
