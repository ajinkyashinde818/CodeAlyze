#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int cnt = 0;
    for (int i = 0; i < max(n - m,1); i++)
    {
        for (int j = 0; j < max(n - m,1); j++)
        {
            bool ans = true;
            for (int k = 0; k < m; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (a[i + k][j + l] != b[k][l])
                        ans = false;
                }
            }
            if (ans)
                cnt++;
        }
    }
    cout << (cnt ? "Yes" : "No") << endl;
}
