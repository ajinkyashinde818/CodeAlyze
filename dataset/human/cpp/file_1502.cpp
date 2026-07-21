#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e20);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a>b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a<b ? : a = b; }


int main() {
    int N;
    cin >> N;
    int t = 3;
    int i = 0;
    if (N == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    while (1) {
        if (t == N)
            break;
        if (t > N) {
            cout << "No" << endl;
            return 0;
        }
        t += (3 + i);
        i++;
    }
    int k = i + 3;
    int l = k - 1;
    v2int table(k, vint(l));
    int pivot = 1;
    rep(i, k) {
        REP(j, i, l) {
            table[i][j] = pivot + j;
            table[j + 1][i] = pivot + j;
        }
        pivot += (l - 1 - i);
    }

    cout << "Yes" << endl;
    cout << k << endl;
    rep(i, k) {
        cout << l << " ";
        rep(j, l) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
