#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    long long int n, a[100010], ans = 0, cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            cnt++;
            a[i] *= -1;
        }
    }

    sort(a, a+n);

    if (cnt % 2) {
        a[0] *= -1;
    }

    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;
}
