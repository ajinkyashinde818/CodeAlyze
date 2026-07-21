#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> as(n);
    long long total_sum = 0;
    for (int& a : as) {
        cin >> a;
        total_sum += a;
    }
    long long best = total_sum;
    sort(as.begin(), as.end());
    long long running_sum = 0;
    for (int i = 0; i+1 < n; i += 2) {
        running_sum += as[i] + as[i+1];
        best = max(best, total_sum - 2*running_sum);
    }
    cout << best << endl;
    return 0;
}
