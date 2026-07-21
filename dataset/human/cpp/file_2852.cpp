#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main(void) {
    i64 n, s = 0, m = 1145141919, c = 0;
    cin >> n;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i]; s += abs(a[i]); m = min(m, abs(a[i]));
        if (a[i] < 0) c++;
    }
    if (c % 2) cout << s - m * 2 << endl;
    else cout << s << endl;
}
