#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)
#define all(c) begin(c),end(c)
#define vmax(c) *max_element(all(c))
#define vmin(c) *min_element(all(c))
 
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2>& map)
{
    for (typename std::map<T1, T2>::const_iterator it = map.begin();
         it != map.end();
         ++it)
    {
        out << (*it);
    }
    return out;
}

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9; 

// 2次元配列を作る
// vector<vi> my_vector(n, vi(m, 0));

// 多次元配列の dump
// for (auto v : my_vector) {
//     cout << v;
// }

ll N;

auto solve() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int c = 0;
    int rc, gc, bc;
    rc = N / R;
    gc = N / G;
    bc = N / B;
    RREP(r, rc + 1) {
        int rr = R * r;
        // cout << "r" << rr << ":";
        int rrr = (N - rr);
        if (rrr == 0)
        {
            c = c + 1;
            // cout << endl;
            continue;
        }
        RREP(g, rrr / G + 1) {
            int gg = G * g;
            // cout << "g" << gg << ":";
            int ggg = N - rr - gg;
            // cout << "gres" << ggg << ":";

            if (ggg == 0)
            {
                c = c + 1;
                // cout << endl;
                continue;
            }

            if (ggg % B == 0) {
                c = c + 1;
            }
        }
        // cout << rrr << ",";
        // cout << endl;
    }
    // cout << endl;
    // cout << "count: " << c << endl;
    // cout << rc << gc << bc;
    return c;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve();
    cout << solve();
}
