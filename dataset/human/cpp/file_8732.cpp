#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    for(int i = 0; i <= n - m; i++)
    {
        for(int j = 0; j <= n - m; j++)
        {
            int count = 0;
            for(int b1 = 0; b1 < m; b1++)
            {
                for(int b2 = 0; b2 < m; b2++)
                {
                    if(b[b1][b2] == a[i+b1][j+b2])
                    {
                        count++;
                    }
                }
            }
            if(count == m * m)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
