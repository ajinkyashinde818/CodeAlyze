#include <iostream>
#include <cstdio>
using namespace std;
    
int main()
{
    int r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;
    for (int i = 0; i <= n / r; i++)
        for (int j = 0; j <= n / g; j++)
        {
            int tmp = n - i * r - j * g;
            if (tmp >= 0 && tmp % b == 0)
                ans++;
        }
    cout << ans;
}
