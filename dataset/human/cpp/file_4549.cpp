#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <numeric>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <limits>
#include <cassert>
#include <bitset>
#include <list>
#include <iomanip>
#include <cctype>

#define for0(i, N)    for (ll i = 0  ; i <  (N); ++i)
#define for1n(i, N)   for (ll i = 1  ; i <= (N); ++i)
#define for1(i, N)    for (ll i = 1  ; i <  (N); ++i)
#define forn(i, N)    for (ll i = 0  ; i <= (N); ++i)
#define forx(i, N, x) for (ll i = (x); i <  (N); ++i)
#define forl(i, N, x, a) for (ll i = (x), a = 0; a < (N);   \
                              i = (i + 1) % (N), ++a)
#define int long long

template<size_t i>
std::bitset<i> operator++(std::bitset<i> b, int){
    static_assert(i <= 64, "Cannot cast 64bit int.");
    return b = (unsigned long long)b + 1;
}

template<size_t i>
std::bitset<i> operator++(std::bitset<i> b){
    static_assert(i <= 64, "Cannot cast 64bit int.");
    auto temp = b;
    b++;
    return temp;
}

template<size_t i>
std::bitset<i> operator--(std::bitset<i> b, int){
    static_assert(i <= 64, "Cannot cast 64bit int.");
    return b = (unsigned long long)b - 1;
}

template<size_t i>
std::bitset<i> operator--(std::bitset<i> b){
    static_assert(i <= 64, "Cannot cast 64bit int.");
    auto temp = b;
    b--;
    return temp;
}

using namespace std;

typedef long long ll;
typedef long double ld;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll>, greater<ll>> pql;
typedef stack<ll> stk;
typedef queue<ll> qu;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vector<ll>> vvll;


signed main(void){
    cin.tie(0); ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);
    int n, r;
    cin >> n >> r;

    if (n >= 10) {
        cout << r;
    } else {
        cout << r+100 * (10 - n);
    }

    return 0;
}
