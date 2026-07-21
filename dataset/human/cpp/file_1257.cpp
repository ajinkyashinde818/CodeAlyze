#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

const long long MOD = 1e9 + 7;

int main()
{
    ll a, b, c, n, ans = 0;
    cin >> a >> b >> c >> n;
    for (int i = 0; i <= 3000; i++)
    {
        for (int j = 0; j <= 3000; j++)
        {
            ll g = i * a + j * b;
            if (g <= n && (n - g) % c == 0)
            {
                ans++;
            }
        }
    }
    cout << ans;
}
