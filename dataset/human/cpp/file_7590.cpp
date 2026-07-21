#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int gcd(int a, int b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int n;
    cin >> n;
    vector<ll> a = {0};
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a.push_back(a.back() + c);
    }
    ll best = 1e16;
    for (int i = 1; i < n; ++i) {
        best = min(best, abs(a.back() - 2 * a[i]));
    }


    cout << best << "\n";
}


int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}

ll fact(ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        res = (res * n) % mod;
        --n;
    }
    return res;
}
