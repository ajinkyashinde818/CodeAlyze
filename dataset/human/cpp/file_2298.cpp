#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) {
    if(a < b) gcd(b, a);
    ll r;

    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<ll> a;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    ll min = LONG_LONG_MAX;
    ll sum = 0;

    for (int j = 0; j < n-1; ++j) {
        if (a.at(j) * (-1) + a.at(j + 1) * (-1) > 0) {
            a.at(j) *= -1;
            a.at(j + 1) *= -1;
        }
    }

    for (int k = 0; k < n; ++k) {
        sum += a.at(k);
    }


    cout << sum << endl;
    return 0;

}
