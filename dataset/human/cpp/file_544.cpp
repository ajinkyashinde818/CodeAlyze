#include <iostream>
using namespace std;

int main()
{
    int r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;
    for (int i = 0; i <= n / r; i++)
    {
        for (int j = 0; j <= (n - i * r) / g; j++)
        {
            if ((n - i * r - j * g) % b == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
