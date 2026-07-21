#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cntMinus = 0;
    long long smallest = 10000000000;
    long long tmp;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        cntMinus += (tmp < 0);
        tmp = abs(tmp);
        a[i] = tmp;
        smallest = min(smallest, tmp);
    }
    long long ans = 0;
    for (int i=0; i<n; i++) ans += a[i];
    if (cntMinus % 2 == 1) ans -= smallest * 2;
    cout << ans << endl;
}
