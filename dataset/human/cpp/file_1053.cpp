#include <bits/stdc++.h>
using namespace std;

int r, g, b, n;

int main()
{
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (r * i + g * j > n)
                continue;
            if ((n - r * i - g * j) % b == 0)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
