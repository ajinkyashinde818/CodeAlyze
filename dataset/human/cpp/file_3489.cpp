#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, m = 1000000001, ans = 0, cnt = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) {
            ++cnt;
            a = -a;
        }
        ans += a;
        m = min(m, a);
    }
	cout << ans - (cnt % 2 == 1 ? m * 2 : 0) << endl;
    return 0;
}
