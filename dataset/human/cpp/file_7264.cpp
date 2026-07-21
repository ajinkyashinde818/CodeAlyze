#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <stack>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <climits>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1000000000 + 7;
const ll INF = LLONG_MAX;
const ll MAX_V = ll(1e5) + 5;
const double EPS = 10e-8;
const double PI = 3.14159265359;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

ll n,a[200005]{};

int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    ll dmin = INF;
    for(int i=1;i<n;i++){
        dmin = min(dmin,abs(a[n]-a[i]*2));
    }
    cout << dmin << endl;
    return 0;
}
