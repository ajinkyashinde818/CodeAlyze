#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

template <typename T>
class SegmentTree
{
public:
    SegmentTree(const int n, const T &unit) : _unit(unit)
    {
        _n = 1 << __lg(2 * n - 1);
        _data.resize(2 * _n, unit);
    }

    SegmentTree(const vector<T> &v, const T &unit) : _unit(unit)
    {
        int n = v.size();
        _n = 1 << __lg(2 * n - 1);
        _data.resize(2 * _n, unit);

        // 最下段に要素をセット
        for (int i = 0; i < n; i++) this->set(i, v[i]);
        // セグメント木を構築
        this->build();
    }

    // k 番目の要素を最下段にセット
    void set(int k, const T &x) { _data[k + _n] = x; }

    // セグメント木を構築
    void build(void)
    {
        for (int i = _n - 1; i > 0; i--) _data[i] = f(_data[2 * i], _data[2 * i + 1]);
    }

    // k番目の値をxに更新する
    void update(int k, const T &x)
    {
        k += _n; // 葉の節点に変換
        _data[k] = x;
        while (k >>= 1) _data[k] = f(_data[2 * k], _data[2 * k + 1]);
    }

    // 区間[a, b)に対してクエリ処理した結果を返す
    T query(int a, int b)
    {
        T left = _unit, right = _unit;
        a += _n, b += _n; // 葉の節点に変換
        for (; a < b; a >>= 1, b >>= 1) {
            if (a & 1) left  = f(left, _data[a++]);
            if (b & 1) right = f(_data[--b], right);
        }
        return f(left, right);
    }

    const T &operator[](size_t k) const { return _data[k + _n]; }
    T &operator[](size_t k) { return _data[k + _n]; }

private:
    int _n;          // 要素数
    vector<T> _data; // データを格納する配列
    T _unit;        // 単位元

    // クエリ処理用の関数
    T f(const T &a, const T &b) { return max(a, b); }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; ll c; cin >> n >> c;
    vector<ll> x(n + 2), v(n + 2);
    for (int i = 1; i <= n; i++) cin >> x[i] >> v[i];
    x[n + 1] = c;

    SegmentTree<ll> l(n + 2, 0), r(n + 2, 0);
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i] + v[i + 1] - (x[i + 1] - x[i]);
    }
    for (int i = n; i > 0; i--) {
        r[i] = r[i + 1] + v[i] - (x[i + 1] - x[i]);
    }
    l.build(); r.build();

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll res1 = l[i] + max<ll>(0, r.query(i + 1, n + 2) - x[i]);
        ll res2 = r[i] + max<ll>(0, l.query(0, i) - (c - x[i]));
        ans = max({ans, res1, res2});
    }
    cout << ans << endl;
    return 0;
}
