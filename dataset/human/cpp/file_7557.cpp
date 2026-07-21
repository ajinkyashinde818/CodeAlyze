#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> ruiseki(N + 1);
    vector<long long> revRuiseki(N + 1);
    for (int i = 0; i < N; i++) {
        ruiseki[i + 1] = A[i] + ruiseki[i];
    }
    reverse(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        revRuiseki[i + 1] = A[i] + revRuiseki[i];
    }
    reverse(revRuiseki.begin(), revRuiseki.end());

    long long ans = 100000000000007;
    for (int i = 1; i < ruiseki.size() - 1; i++) {
        ans = min(abs(ruiseki[i] - revRuiseki[i]), ans);
    }
    cout << ans << endl;
}
