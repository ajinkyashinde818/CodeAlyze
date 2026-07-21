#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m], ab[m][m];
    bool isGood = true;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    ab[x][y] = a[i + x][j + y];
                }
            }
            isGood = true;
            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    if (ab[x][y] != b[x][y])
                    {
                        isGood = false;
                    }
                }
            }
            if (isGood == true)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
