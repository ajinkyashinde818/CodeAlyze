#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll n; cin >> n;
    vector<ll> a;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll _a; cin >> _a;
        a.push_back(_a);
        sum += _a;
    }
    ll closest = a[0];
    ll subsum = a[0];
    for (int i = 1; i < n-1; i++) {
        subsum += a[i];
        if (abs(closest - sum/2) > abs(subsum - sum/2)) {
            closest = subsum;
        }
    }
    cout << abs(closest * 2 - sum) << endl;
    return 0;
}
