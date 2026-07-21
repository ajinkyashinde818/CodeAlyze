#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll a[n];
    ll numMinus = 0;
    ll res = 0;
    ll minNum = 1000000009;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            numMinus++;
            res -= a[i];
            minNum = (minNum > -a[i]) ? -a[i] : minNum;
        } else {
            res += a[i];
            minNum = (minNum > a[i]) ? a[i] : minNum;
        }
    }

    if (numMinus % 2 == 1) res = res - 2 * minNum;

    cout << res << endl;
}
