#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int64_t ans = 0, mi = int(1e10);
    int cnt_minus = 0;
    int is_zero = false;

    for (const auto &a: A) {
        if (a < 0) cnt_minus++;
        if (a == 0) is_zero = true;
        ans += abs(a);
        mi = min(abs(a), mi);
    }

    cout << ans - 2 * ((is_zero or cnt_minus % 2 == 0) ? 0 : mi) << endl;
}
