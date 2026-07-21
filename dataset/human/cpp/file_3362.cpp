#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>
#include <cmath>
#include <complex>
#include <algorithm>
#include <utility>
#include <regex>
#include <cstdint>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll INF = 1e+11;/* 1e+9a */
namespace utils{

    class Repeater{
        int st;
        int ed;
        int d;
    public:
        class rep_iterator{
            int i; int d;
        public:
            rep_iterator(int x, int pd) :i(x), d(pd) {}

            int& operator*(){ return i; }
            bool operator==(const rep_iterator& k) const { return i == k.i; }
            bool operator!=(const rep_iterator& k) const { return i != k.i; }
            rep_iterator& operator++(){ i+=d; return *this; }
        };

        Repeater(int N) :st(0), ed(N), d(1) {}
        Repeater(int b, int e) :st(b), ed(e), d(1) {if(st > ed){ st--; ed--; d = -1; } }

        rep_iterator begin() const{ return rep_iterator(st, d); }
        rep_iterator end() const{ return rep_iterator(ed, d); }

    };

    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool min_update(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool max_update(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }
#define ALL(x) begin(x), end(x)
#define rALL(x) rbegin(x), rend(x)
};
using namespace utils;


void sub_main(istream &cin) {
    ll N;
    cin >> N;
    if(!cin) return;
    vector<ll> A(N);
    ll sum = 0;
    ll negative_count = 0;
    ll minimum = INF;
    for (auto &&a : A) {
        cin >> a;
        if(a < 0) {
            negative_count++;
            a = -a;
        }
        sum += a;
        minimum = min(a, minimum);
    } // end a
    ll ans = sum - (negative_count % 2 == 1 ? 2 * minimum : 0);

    cout << ans << endl;

}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    cerr << "DEBUG MODE" << endl;
    string test_cases = "test_D.txt";
    auto fs = fstream(test_cases, fstream::in);
    int lp = 0;
    while(fs) {
        lp++;
        cout << lp <<  "#------\n";
        sub_main(fs);
    }
    cout << "------#" << endl;
    if(lp <= 1) sub_main(cin);
#else
    sub_main(cin);
#endif
    return 0;
}
