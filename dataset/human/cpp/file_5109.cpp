#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, r;
    cin >> n >> r;

    int rate_difference = 100 * (10 - n);

    if (n < 10) {
        cout << r + rate_difference << endl;
    }
    else {
        cout << r << endl;
    }
    return 0;
}
