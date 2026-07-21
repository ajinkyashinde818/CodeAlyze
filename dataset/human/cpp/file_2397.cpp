#include <bits/stdc++.h>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>
using namespace std;
constexpr char nl = '\n';
using ll = long long;
using boost::irange;
using boost::adaptors::reversed;
namespace rng { using namespace boost; using namespace boost::range; }
struct init_ { init_(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10); } } init_;

template<class C> auto operator>>(istream& in, C& c) -> typename enable_if<!is_void<decltype(c.begin())>::value && !is_same<C, string>::value, istream&>::type {
    for (auto& v : c) { in >> v; } return in; }
template<class C> auto operator<<(ostream& out, const C& c) -> typename enable_if<!is_void<decltype(c.begin())>::value && !is_same<C, string>::value, ostream&>::type {
    int i = 0; for (const auto& v : c) { if (i++) { out << ' '; } out << v; } return out; }
template<size_t N, class T, class R> using when_last = typename enable_if<N == tuple_size<remove_reference_t<T>>::value - 1, R>::type;
template<size_t N, class T, class R> using when_init = typename enable_if<N != tuple_size<remove_reference_t<T>>::value - 1, R>::type;
template<size_t N = 0, class T> auto operator>>(istream& in, T&& t) -> when_last<N, T, istream&> { return in >> get<N>(t); }
template<size_t N = 0, class T> auto operator>>(istream& in, T&& t) -> when_init<N, T, istream&> { return operator>><N + 1>(in >> get<N>(t), forward<T>(t)); }
template<size_t N = 0, class T> auto operator<<(ostream& out, const T& t) -> when_last<N, T, ostream&> { return out << get<N>(t); }
template<size_t N = 0, class T> auto operator<<(ostream& out, const T& t) -> when_init<N, T, ostream&> { return operator<<<N + 1>(out << get<N>(t) << ' ', t); }

#ifdef LOCAL
constexpr auto color_s_ = "\033[2m\033[33m", color_e_ = "\033[0m";
template<class T> void trace_(const T& v) { cerr << v; }
template<class T> void trace_(const vector<vector<T>>& m) { cerr << "\n"; for (const auto& v : m) { trace_(v); cerr << "\n"; } }
template<class T> void trace_(const char* s, const T& v) { cerr << color_s_ << s << "="; trace_(v); cerr << color_e_ << "\n"; cerr.flush(); }
template<class T, class... Ts> void trace_(const char* s, const T& v, const Ts&... vs) { cerr << color_s_; for (; *s != ','; ++s) { cerr << *s; } cerr << "="; trace_(v); cerr << ","; trace_(++s, vs...); }
#define TRACE(...) trace_(#__VA_ARGS__, __VA_ARGS__)
#else
#define TRACE(...)
#endif

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int negs = 0;
    ll sum = 0;
    int min_a = numeric_limits<int>::max();
    for (int& ai : a) {
        if (ai < 0) {
            negs++;
            ai = -ai;
        }
        sum += ai;
        min_a = min(min_a, ai);
    }
    if (negs % 2 == 0) {
        cout << sum << nl;
    } else {
        cout << (sum - 2 * min_a) << nl;
    }
}
