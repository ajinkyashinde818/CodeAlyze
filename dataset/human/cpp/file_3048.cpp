#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<int> al, bl;
int main() {
    int n;
    cin >> n;
    vector<ll> vec;
    int count = 0;
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        if (a < 0) {
            count++;
            a *= -1;
        }
        ret += a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    if (count % 2) {
        ret -= vec[0] * 2;
    }
    cout << ret << endl;
    return 0;
}
