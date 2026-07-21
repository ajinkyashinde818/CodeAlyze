#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int minus = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] < 0) {
            minus++;
            a[i] *= -1;
        }
    }
    ll sum = 0;
    auto min_itr = min_element(a.begin(), a.end());
    for (auto it = a.begin(); it != a.end(); it++) {
        if (it == min_itr && minus % 2)
            sum += *it * -1;
        else
            sum += *it;
    }
    cout << sum << endl;
}
