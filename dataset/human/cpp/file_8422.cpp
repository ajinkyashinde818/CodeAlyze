#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    for (auto i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }

    for (auto i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        b.push_back(s);
    }

    for (auto i = 0; i < n - m + 1; i++)
    {
        for (auto j = 0; j < n - m + 1; j++)
        {
            int sum = 0;
            for (auto k = 0; k < m; k++)
            {
                for (auto l = 0; l < m; l++)
                {
                    if (a[i + k][j + l] == b[k][l])
                    {
                        sum += 1;
                    }
                }
            }

            if (sum == m * m)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
