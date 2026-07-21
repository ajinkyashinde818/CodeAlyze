#include <bits/stdc++.h>
using namespace std;

/* define const */

/* finish defineing const */

int m, n;
string a[60];
string b[60];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    // input

    bool f = true;
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            f = true;
            for (int k = 0; k < m; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (a[i + k][j + l] != b[k][l])
                    {
                        f = false;
                    }
                }
            }
            if (f == true)
            {
                goto L;
            }
        }
    }

L:
    if (f)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
