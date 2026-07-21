#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long sum = accumulate(a.begin(), a.end(), 0L);
    long snuke = 0;
    long ans = LONG_MAX;
    for (int i = 0; i < n-1; i++) {
        snuke += a[i];
        ans = min(ans, abs(snuke - (sum - snuke)));
    }
    cout << ans << endl;

    return 0;
}
