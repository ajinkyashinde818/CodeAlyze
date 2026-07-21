#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    if (n < 10) cout << (10 - n) * 100 + r << '\n';
    else cout << r << '\n'; 
    return 0;
}
