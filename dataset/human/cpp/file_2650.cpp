#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, t, Cnt;
ll sum;
bool z;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int m = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t < 0) {
            ++Cnt;
            m = min(m, -t);
            sum += -t;
        } else if (t > 0) {
            m = min(m, t);
            sum += t;
        } else {
            z = true;
        }
    }
    if (!z && (Cnt & 1)) {
        sum -= m * 2;
    }
    cout << sum << endl;

    return 0;
}
