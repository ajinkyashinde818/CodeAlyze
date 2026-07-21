#include<bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r;
    cin >> n >> r;
    if (n >= 10) cout << r << '\n';
    else cout << r + 100 * (10 - n) << '\n';
}
