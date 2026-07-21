#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, count = 0, ans = 0;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            count++;
            a *= -1;
        }
        S.at(i) = a;
    }
    if (count % 2 == 1) {
        sort(S.begin(), S.end());
        S.at(0) *= -1;
    }
    for (int i = 0; i < N; i++) {
        ans += S.at(i);
    }
    cout << ans << endl;
}
