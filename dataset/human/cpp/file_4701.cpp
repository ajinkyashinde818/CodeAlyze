#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    if (n >= 10) cout << r;
    else cout << r + (100 * (10 - n));
    return 0;
}
