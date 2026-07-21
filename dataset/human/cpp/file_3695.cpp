#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long N, a[100010];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int count = 0;
    long long m, ans = 0;
    bool zero = false;
    m         = abs(a[0]);
    for (int i = 0; i < N; ++i) {
        if (a[i] < 0) {
            ++count;
        } else if (a[i] == 0) {
            zero = true;
        }
        ans += abs(a[i]);
        m = min(abs(a[i]), m);
    }
    if (!zero && count % 2 != 0) {
        ans -= 2 * m;
    }
    cout << ans << endl;

    return 0;
}
