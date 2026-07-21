#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll s = 0;
    int c = 0, m = 1 << 30;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a <= 0) {
            c++;
        }
        m = min(m, abs(a));
        s += abs(a);
    }

    if (c % 2) {
        s -= m * 2;
    }

    cout << s << endl;

    return 0;
}
