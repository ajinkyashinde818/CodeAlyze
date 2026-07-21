#include <iostream>
using namespace std;

int main()
{
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int i, j, iplusj, remaining;
    int cnt = 0;
    for (i = 0; i <= n; i += r)
    {
        for (j = 0; (iplusj = (i + j)) <= n; j += g)
        {
            remaining = n - iplusj;
            if (!(remaining % b))
            {
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
