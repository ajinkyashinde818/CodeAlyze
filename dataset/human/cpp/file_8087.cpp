#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[200200], cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_b += a[i];
    }

    long long ans = 1LL<<60;
    for (int i = 0; i < n - 1; i++) {
        cnt_a += a[i];
        cnt_b -= a[i];
        ans = min(ans, abs(cnt_a - cnt_b));
    }

    cout << ans << endl;
    return 0;
}
