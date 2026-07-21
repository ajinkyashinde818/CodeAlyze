#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long ans = 0;
    int mn = 1000000000;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(A[i]);
        if (A[i] < 0) cnt++;
        mn = min(mn, abs(A[i]));
    }

    if (cnt % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << ans - 2 * mn << endl;
    }

    return 0;
}
