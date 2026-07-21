#include <algorithm>
#include <cassert>
// #include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
// #include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int n;
ll d;

ll loc[100005];
ll val[100005];

ll prefixDiff[100005];
ll maxPrefixDiff[100005];

ll suffixDiff[100005];
ll maxSuffixDiff[100005];

void init() {
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr += val[i];
        prefixDiff[i+1] = curr - loc[i];
    }
    for(int i = 1; i <= n; i++) {
        maxPrefixDiff[i] = max(prefixDiff[i], maxPrefixDiff[i-1]);
    }
    curr = 0;
    for(int i = 0; i < n; i++) {
        curr += val[n-1-i];
        suffixDiff[i+1] = curr - (d - loc[n-1-i]);
    }
    for(int i = 1; i <= n; i++) {
        maxSuffixDiff[i] = max(suffixDiff[i], maxSuffixDiff[i-1]);
    }
}

int main() {
    scanf("%d%lld", &n, &d);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &loc[i], &val[i]);
    }
    init();
    ll ret = 0;
    {
        ll curr = 0;
        for(int i = 0; i < n; i++) {
            curr += val[i];
            ret = max(ret, curr - loc[i]);
        }
    }
    {
        ll curr = 0;
        for(int i = 0; i < n; i++) {
            curr += val[n-1-i];
            ret = max(ret, curr - (d - loc[n-1-i]));
        }
    }
    {
        // right, then left
        ll curr = 0;
        for(int i = 0; i < n; i++) {
            curr += val[i];
            ret = max(ret, curr - 2 * loc[i] + maxSuffixDiff[n-1-i]);
        }
    }
    {
        // left, then right
        ll curr = 0;
        for(int i = 0; i < n; i++) {
            curr += val[n-1-i];
            ret = max(ret, curr - 2 * (d - loc[n-1-i]) + maxPrefixDiff[n-1-i]);
        }
    }
    printf("%lld\n", ret);
}
