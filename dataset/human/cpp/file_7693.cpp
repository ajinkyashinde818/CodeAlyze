#include <iostream>

using namespace std;

int main (void)
{
    int n;
    cin >> n;

    long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }

    for (int i = 1; i < n - 1; i++) {
        a[i] = a[i-1] + a[i];
    }

    long x = a[0];
    long y = total - x;
    long ans = abs(x - y);
    for (int i = 1; i < n - 1; i++) {
        x = a[i];
        y = total - x;
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;

    return 0;
}
