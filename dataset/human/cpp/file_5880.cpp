#include <algorithm>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <chrono>
#include <random>
#include <thread>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define val const auto
#define var auto

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef complex<double> point;

template <typename T, std::size_t N>
struct _v_traits {
    using type = std::vector<typename _v_traits<T, N - 1>::type>;
};
template <typename T>
struct _v_traits<T, 1> {
    using type = std::vector<T>;
};
template <typename T, std::size_t N = 1>
using vec = typename _v_traits<T, N>::type;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) {
            os << ",";
        }
        os << *it;
    }
    return os << "}";
}

template <typename T>
T read_next()
{
    T ret;
    cin >> ret;
    return ret;
}

template <typename T>
void isort(std::vector<T>& v, std::function<bool(T, T)> comp = less<T>())
{
    sort(v.begin(), v.end(), comp);
}
template <typename T>
std::vector<T> sort(std::vector<T> v, std::function<bool(T, T)> comp = less<T>())
{
    isort(v);
    return v;
}
template <typename T1, typename T2>
std::vector<T2> rmap(const std::vector<T1>& v, std::function<T2(T1)> f)
{
    std::vector<T2> t;
    t.reserve(v.size());
    for (const auto& i : v)
        t.push_back(f(i));
    return t;
}
std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> res;
    size_t current = 0, found;
    while ((found = str.find_first_of(delim, current)) != std::string::npos) {
        res.push_back(std::string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(std::string(str, current, str.size() - current));
    return res;
}
string join(const std::vector<string>& v, string delim)
{
    string ret = "";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) {
            ret += delim;
        }
        ret += *it;
    }
    return ret;
}

using i64 = int64_t;
using i32 = int32_t;

using ll = i64;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> xv(n);
    repeat (i, n) {
        cin >> xv[i].first >> xv[i].second;
    }
    sort(all(xv));
    ll ret = 0;

    for (int k = 0; k < 2; k++) {
        vector<ll> back(n + 1, -100000000000LL);
        {
            back[n] = 0;
            ll cur = 0;
            for (int i = n - 1; i >= 0; i--) {
                cur += xv[i].second;
                back[i] = max(back[i+1], cur-(c-xv[i].first));
            }
        }
        dump(back);
        {
            ll cur = 0;
            ret = max(ret, back[0]);
            for (int i = 0; i < n; i++) {
                cur += xv[i].second;
                dump(cur);
                dump(xv[i].first);
                dump(back[i + 1]);
                ret = max(ret, (cur - xv[i].first * 2) + back[i + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            xv[i].first = c - xv[i].first;
        }
        reverse(all(xv));
    }
    cout << ret << endl;

    return 0;
}
