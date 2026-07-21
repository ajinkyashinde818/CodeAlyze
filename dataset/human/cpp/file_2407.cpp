#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    int N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    ll count = 0;
    for (int i=0; i<N; i++) {
        if (A[i] < 0) count++;
    }
    
    ll ans = 0;
    ll mini = 1000000000;
    
    if (count % 2 == 0) {
        for (int i=0; i<N; i++) {
            ans += abs(A[i]);
        }
        cout << ans << endl;
        return 0;
    }
    else {
        for (int i=0; i<N; i++) {
            if (A[i] < 0) A[i] = -A[i];
            ans += A[i];
            mini = min(mini, A[i]);
        }
        cout << ans - 2 * mini << endl;
    }
}
