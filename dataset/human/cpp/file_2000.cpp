#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
static const uint64_t MOD = 1000000007LL;
// uint64_t dp[100005][13];
//

int main()
{
    int n;
    cin >> n;

    vector<long> a(n);
    vector<long> ab(n);
    long x = 1000000007LL;
    int nr_neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            nr_neg++;
            ab[i] = - a[i];
        } else {
            ab[i] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (ab[i] < x)
            x = ab[i];
    }

    if (nr_neg % 2 == 0) {
        x = 0;
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ab[i];
    }
    ans -= x;
    ans -= x;

    cout << ans << endl;
}
