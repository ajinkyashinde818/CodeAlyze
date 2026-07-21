#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;

    ll ret = 1;
    ll fin_count = 0;
    ll calc_count = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if ((i % 2 == 0) == (s[i] == 'W'))fin_count++;
        else {
            ret *= fin_count;
            ret %= mod;
            fin_count--;
            calc_count++;
        }
    }

    for (ll i = 1; i <= n; i++) {
        ret *= i;
        ret %= mod;
    }
    cout << (calc_count == n ? ret : 0) << endl;
    return 0;
}
