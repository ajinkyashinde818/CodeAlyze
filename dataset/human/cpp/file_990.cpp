#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int r, g, b, n;
    cin >> r;
    cin >> g;
    cin >> b;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n / r + 1; i++)
    {
        for (int j = 0; j < (n - i * r) / g + 1; j++)
        {
            if ((n - i * r - j * g) % b == 0)
                cnt++;
        }
    }
    cout << cnt << endl;
}
