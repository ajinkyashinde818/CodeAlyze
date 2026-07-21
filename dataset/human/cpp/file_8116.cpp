#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n;
    cin >> n;

    vector<llint> a(n);
    llint sumall = 0;
    for(int in=0;in<n;in++) {
        cin >> a.at(in);
        sumall += a.at(in);
    }
    vector<llint> sum(n+1);
    for(int in=0;in<n;in++) {
        if(in==0) sum.at(in) = 0;
        else sum.at(in) = sum.at(in-1) + a.at(in-1);
    }

    llint ans = 1e18, m1, m2;
    for(int in=0;in<n-1;in++) {
        m1 = sum.at(in+1);
        m2 = sumall - sum.at(in+1);
        ans = min(ans, abs(m1-m2));
    }
    cout << ans << endl;
    return 0;
}
