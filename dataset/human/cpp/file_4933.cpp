#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int iinf = 1 << 28;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;

void work() {
   int n, dr; cin>>n>>dr;
    if (n >= 10) {
        cout << dr;
    } else {
        cout << dr + 100 * (10 - n);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    work();

    return 0;
}
