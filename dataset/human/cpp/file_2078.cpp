#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{
    ll N;
    ll A[100000];
    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll p = 0;
    ll min = A[0] < 0 ? A[0] * -1 : A[0];
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (A[i] < 0) {
            p = 1 - p;
            A[i] = A[i] * -1;
        }
        min = min < A[i] ? min : A[i];
        ans += A[i];
    }
    if (p == 1) {
        ans -= min * 2;
    }
    cout << ans << endl;
}
