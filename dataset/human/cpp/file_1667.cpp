/*
#include <boost/functional/hash.hpp>
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int mlint;
*/
// #include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <tuple>
#include <string>
#include <functional>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <bitset>
#include <stack>
#include <iomanip>

using namespace std;
typedef int64_t i64;
typedef double db;
typedef vector<vector<int64_t>> mat;
typedef pair<int,int> pii;
typedef pair<int64_t,int> pli;
typedef pair<db,int> pdi;

#define esc(x) cout << (x) << endl,exit(0)
#define inf(T) (numeric_limits<T>::max() / 2 - 1)
#define each(i,v) for(auto i = begin(v),end_copy = end(v); i != end_copy; ++i)
#define reach(i,v) for(auto i = rbegin(v),rend_copy = rend(v); i != rend_copy; ++i)
#define urep(i,s,t) for(int64_t i = (s),t_copy = (t); i <= t_copy; ++i)
#define drep(i,s,t) for(int64_t i = (s),t_copy = (t); i >= t_copy; --i)
#define rep(i,n) urep(i,0,(n) - 1)
#define rep1(i,n) urep(i,1,(n))
#define rrep(i,n) drep(i,(n) - 1,0)
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define vct vector
#define prque priority_queue
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define ers erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second

void setup(uint8_t prec = 10) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(prec);

    #ifdef Local

    #define debug 1
    #define print(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

    cout << "-- Execution At Local ---\n" << "\n<Standard Output>\n\n";
    auto print_atexit = []() {
        time_t end_time = time(NULL);
        struct tm *ret = localtime(&end_time);
        cout << "\n----------------\n";
        cout << "\nSuccessfully Executed At " << (ret -> tm_hour) << ":" << (ret -> tm_min) << ":" << (ret -> tm_sec) << "\n\n";
    };
    atexit(print_atexit);

    #endif
}

template <class T, class U> ostream& operator << (ostream& s, pair<T,U> p) { return s << p.fir << " " << p.sec; }
template <class T> ostream& operator << (ostream& s, vector<T>& v) { for(auto i = v.begin(); i != v.end(); i++) { if(i != begin(v)) s << " "; s << *i; } return s; }

template <class T> void hash_combine(size_t &seed, T const &key) {
    hash<T> hasher;
    seed ^= hasher(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &p) const {
            size_t seed(0);
            hash_combine(seed,p.first);
            hash_combine(seed,p.second);
            return seed;
        }
    };
}

bool odd(i64 x) { return x & 1; }
bool even(i64 x) { return !odd(x); }
bool parity(i64 x, i64 y) { return odd(x) ^ even(y); }
bool bit(i64 n, uint8_t e) { return n >> e & 1; }
int ilog(i64 x, uint64_t b) { if(x) return ilog(x / b,b) + 1; return -1; }
i64 qceil(i64 x, i64 y) { return x > 0 ? (x - 1) / y + 1 :  x / y; }
uint64_t gcd(uint64_t a, uint64_t b) { if(!b) return abs(a); if(a % b) return gcd(b, a % b); return b; }
uint64_t lcm(uint64_t a, uint64_t b) { if(a & b) return a / gcd(a, b) * b; return 0; }
template <class T, class U> bool chmax(T& m, U x) { if(m < x) { m = x; return 1; } return 0; }
template <class T, class U> bool chmin(T& m, U x) { if(m > x) { m = x; return 1; } return 0; }
template <class T> T cmprs(T& v) {
    T tmp = v,ret = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),end(tmp));
    each(i,ret) *i = l_bnd(all(tmp),*i) - begin(tmp) + 1;
    return ret;
}

const int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const i64 mod = 1e9 + 7;
const db eps = 1e-15;

int n;

int main() {
    setup();

    cin >> n;
    int i = 1;
    while(i * (i - 1) / 2 < n) ++i;
    if(n == i * (i - 1) / 2) {
        cout << "Yes\n";
        cout<<i<<endl;
        vct<vct<int>> s(i);
        int x=1;
        urep(j,0,i-2)urep(l,j+1,i-1){
            s[j].emb(x);
            s[l].emb(x);
            x++;
        }
        rep(l,i){
            cout << s[l].size();
            rep(k,s[l].size()){
                cout << " ";
                cout << s[l][k];
            }
            cout << endl;
        }
    } else cout << "No\n";
}
