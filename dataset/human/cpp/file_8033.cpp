#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    long ans = numeric_limits<long>::max();
    for (int i = n - 2; i >= 0; i--) {
        ans = min(ans, abs(2 * a[i] - a[n - 1]));
    }
    cout << ans << endl;
    return 0;
}
