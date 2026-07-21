#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int N_MAX = 200000;
int main (void) {
    int N;
    int a[N_MAX];
    ll X = 0;
    ll xi = 0;
    ll ans = LLONG_MAX;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        X += a[i];
    }

    for (int i = 0; i < N - 1; i++) {
        xi += a[i];
        ans = min(ans, abs(X - 2 * xi));
    }

    cout << ans << endl;

    return 0;
}
