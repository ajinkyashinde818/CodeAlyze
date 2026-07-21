#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    for (i = 0; i < m; i++)
    {
        cin >> b.at(i);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - m + 1; j++)
        {
            int key = 0;
            while (a.at(i + key).substr(j, m) == b.at(key))
            {
                key++;
                if (key == m || i + key == n)
                {
                    if (key == m)
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
