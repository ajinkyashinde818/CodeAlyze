#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    ll sunuke_sum, arai_sum, total;
    ll ans = 2000000000;
    sunuke_sum = 0;
    arai_sum = 0;
    total = 0;
    cin >> N;
    vector<ll>a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        total += a.at(i);
    }

    for (int i = 0; i < N-1; i++) {
        sunuke_sum += a[i];
        arai_sum = total-sunuke_sum;
        ans = min(ans, abs(sunuke_sum-arai_sum));
    }
    cout << ans << endl;
}
