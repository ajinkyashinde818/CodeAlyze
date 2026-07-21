#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r << "\n";
    else {
        cout << r + (100 * (10 - n)) << "\n";
    }
    return 0;
}
