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

namespace utils{
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
    ///----- aliases
    using ll = long long int;
    using ull = unsigned long long;

    using f32 = float;
    using f64 = double;

    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> inline bool CHMIN(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> inline bool CHMAX(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }

    ///----- vector I/O
    template<class T>
    vector<T> VEC(size_t n, T t){
        return vector<T>(n, t);
    }

    template<class ...Ts>
    auto VEC(size_t n, Ts ... ts){
        return vector<decltype(VEC(ts...))>(n, VEC(ts...));
    }

    template<class T>
    vector<T> VIN(istream& is, size_t n){
        vector<T> v(n);
        for (int i = 0; i < n; ++i) {
            is >> v[i];
        } // end i
        return v;
    }

    template<class T>
    auto VIN(istream& is, size_t n, size_t ts...){
        auto v = vector<decltype(VIN<T>(is, ts))>(n);
        for (auto &&x : v) {
            x = VIN<T>(is, ts);
        } // end x
        return v;
    }

    template<class T>
    bool VOUT(ostream& os, vector<T>& v){
        for (auto &&x : v) {
            os << x  << ' ';
        } // end x
        return !!os;
    }

    template<class T>
    bool VOUT(ostream& os, vector<vector<T>>& v, char endc = '\n'){
        for (auto &&vs : v) {
            VOUT(os, vs);
            os << endc;
        } // end vs
        return !!os;
    }

    ///----- tuple I/O
    template <class S, class T>
    istream& operator>>(istream& is, tuple<S, T>& t){
        return is >> get<0>(t) >> get<1>(t);
    }

    template <class S, class T, class U>
    istream& operator>>(istream& is, tuple<S, T, U>& t){
        return is >> get<0>(t) >> get<1>(t) >> get<2>(t);
    }

    template <class S, class T>
    ostream& operator<<(ostream& os, const tuple<S, T>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t);
    }

    template <class S, class T, class U>
    ostream& operator<<(ostream& os, const tuple<S, T, U>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t) << ' ' <<  get<2>(t);
    }

    ///----- constants
    constexpr ll INFLL   = 1'000'000'000'000'000'020ll;
    constexpr ll INF     = 1'000'000'009;
    constexpr f64 PI      = 3.14'159'265'358'979'323'846;
    constexpr f64 EPS     = 1e-12;
}
using namespace utils;


class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}

    int N;

    vector<int> A, B;
    bool input() {
        is >> N;
        A = VIN<int>(is, N);
        B = VIN<int>(is, N);
        return !!is;
    }

    void run();
};

void solver::run(){
    if(!input()) return;
    vector<int> sa(N+1), sb(N+1);
    for (int i = 0; i < N; ++i) {
        sa[A[i]]++;
        sb[B[i]]++;
    } // end i
    for (int i = 0; i <= N; ++i) {
        if(sa[i] + sb[i] > N){
            os << "No\n";
            return;
        }
    } // end i

    for (int i = 0; i < N; ++i) {
        sa[i+1] += sa[i];
        sb[i+1] += sb[i];
    } // end i

    int x = 0;
    for (int i = 0; i < N; ++i) {
        CHMAX(x, sa[i+1]- sb[i]);
    } // end i

    os << "Yes\n";
    for (int i = 0; i < N; ++i) {
        os << B[(i-x+N)%N] << ' ';
    } // end i
    os << endl;

}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_f.txt";
    cerr << test_cases << " -->" << endl;
    auto fs = fstream(test_cases, fstream::in);
    int loop = 0;
    while(fs) {
        loop++;
        cout << '#' << loop << "#------\n";
        solver(fs, cout).run();
    }
    if(loop <= 1) {
        cout << "===" << endl;
        while(cin) solver(cin, cout).run();
    }
#else
    solver(cin, cout).run();
#endif
    return 0;
}
