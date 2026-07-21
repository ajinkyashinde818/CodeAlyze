#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (as[i] < 0 && i < n - 1) {
            as[i] = -as[i];
            as[i + 1] = -as[i + 1];
        }
        sum += as[i];
    }
    if (as[n - 1] >= 0) {
        cout << sum << endl;
        return 0;
    }
    sum -= 2 * as[n - 1];
    as[n - 1] = -as[n - 1];
    sum -= 2 * *min_element(as.begin(), as.end());
    cout << sum << endl;
}
