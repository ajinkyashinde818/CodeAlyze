#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll A[200000];
ll sm(ll* A,ll n){
    ll s= 0;
    for (int i = 0; i < n; ++i) {
        s += A[i];
    }
    return s;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    ll sum_t = A[0];
    ll sum = accumulate(A, A+ n, 0ll);
    ll mi = abs(2*A[0] - sum);
    for (int i = 1; i < n-1; ++i) {
        sum_t += A[i];
        mi = min(abs(2*sum_t - sum), mi);
    }
    cout << mi << "\n";




}
