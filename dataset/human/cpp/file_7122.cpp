#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long int a[200010];
    long long int ans = 1LL << 60;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i+1] += a[i];
    }

    for (int i = 0; i < n-1; i++) {
        if (ans > abs((a[n-1]-a[i])-a[i])) {
            ans = abs((a[n-1]-a[i])-a[i]);
        }
    }
    cout << ans << endl;
}
