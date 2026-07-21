#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    long long n, c, x[100002], v[100002];

    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
    }

    long long ans = 0;
    long long lsum = 0, rsum = 0;
    long long lmaxi[100002] = {0}, rmaxi[100002] = {0};
    for(int i = 1; i <= n; i++) {
        lsum += v[i];
        lmaxi[i] = max(lmaxi[i - 1], lsum - x[i]);
        ans = max(ans, lmaxi[i]);
    }
    for(int i = n; i > 0; i--) {
        rsum += v[i];
        rmaxi[i] = max(rmaxi[(i + 1) % (n + 1)], rsum - (c - x[i]));
        ans = max(ans, rmaxi[i]);
    }

    for(int i = 0; i <= n; i++) {
        ans = max(lmaxi[i] - x[i] + rmaxi[(i + 1) % (n + 1)], ans);
    }
    for(int i = n; i >= 0; i--) {
        ans = max(rmaxi[i] - (c - x[i]) + lmaxi[(i - 1 + n + 1) % (n + 1)], ans);
    }
    cout << ans << endl;
}
