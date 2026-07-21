#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;

ll rgt[200000];
ll lft[200000];
ll rgtend[200000];
ll rgtback[200000];
ll lftend[200000];
ll lftback[200000];

int main() {
    ll N, C;
    cin >> N >> C;
    ll x[N], v[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
    }
    rgt[0] = 0;
    lft[0] = 0;
    for (int i = 0; i < N; i++) {
        rgt[i + 1] = rgt[i] + v[i];
        lft[i + 1] = lft[i] + v[N - 1 - i];
    }
    rgtend[0] = 0;
    rgtback[0] = 0;
    lftend[0] = 0;
    lftback[0] = 0;
    for (int i = 0; i < N; i++) {
        rgtend[i + 1] = max(rgtend[i], rgt[i + 1] - x[i]);
        rgtback[i + 1] = max(rgtback[i], rgt[i + 1] - x[i] * 2);
        lftend[i + 1] = max(lftend[i], lft[i + 1] - (C - x[N - 1 - i]));
        lftback[i + 1] = max(lftback[i], lft[i + 1] - (C - x[N - 1 - i]) * 2);
    }
    ll rgtmax = 0;
    ll lftmax = 0;
    for (int i = 0; i < N + 1; i++) {
        rgtmax = max(rgtmax, rgtend[i] + lftback[N - i]);
        lftmax = max(lftmax, lftend[i] + rgtback[N - i]);
    }
    cout << max(rgtmax, lftmax) << endl;
}
