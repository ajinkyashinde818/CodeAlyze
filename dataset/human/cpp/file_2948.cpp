#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] < 0) {
            A[i] = -A[i];
            cnt++;
        }
    }
    sort(A.begin(), A.end());

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i];
    }
    if(cnt % 2 != 0) ans = ans -(2 * A[0]);

    cout << ans << endl;

    return 0;
}
