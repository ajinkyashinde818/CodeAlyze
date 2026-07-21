#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    vector<int> a;
    cin >> n;

    int n_minus = 0;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (j < 0) n_minus++;
        a.emplace_back(abs(j));
    }

    uint64_t ans = 0;
    int minimum = INT32_MAX;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        minimum = min(minimum, a[i]);
    }
    if (n_minus % 2 == 1) {
        ans -= minimum * 2;
    }

    cout << ans << endl;
}
