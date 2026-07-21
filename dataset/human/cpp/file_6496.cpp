#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    ll r = 1;
    int l = 0;
    for (int i = 0; i < n * 2; i++) {
        if (s[i] == 'W' ^ i % 2 == 0) {
            l++;
        } else {
            if (l <= 0) {
                cout << 0 << endl;
                exit(0);
            }
            (r *= l) %= P;
            l--;
        }
    }

    if (l != 0) {
        cout << 0 << endl;
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        (r *= i + 1) %= P;
    }

    cout << r << endl;

    return 0;
}
