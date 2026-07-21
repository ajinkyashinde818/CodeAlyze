#include <iostream>
#include <algorithm>

using namespace std;

long long com_sum[200009];


void solve() {
    int n;
    cin >> n;
    int ai;
    cin >> ai;
    com_sum[0] = ai;
    for (int i=1; i<n; ++i) {
        cin >> ai;
        com_sum[i] = com_sum[i-1] + ai;
    }
    long long min_dif = 2e14, dif;
    for (int i=0; i < n-1; ++i) {
        dif = abs(com_sum[n-1] - 2*com_sum[i]);
        if (dif < min_dif)
            min_dif = dif;
    }
    cout << min_dif;
}

int main() {

	solve();
    return 0;
}
