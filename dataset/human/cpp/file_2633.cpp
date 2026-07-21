#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    long long sum = 0;
    long long mn = 1e10;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a < 0) {
            cnt++;
            a *= -1;
        }
        mn = min(mn, a);
        sum += a;
    }

    if (cnt % 2 == 1) sum -= 2 * mn;
    cout << sum << endl;
    return 0;
}
