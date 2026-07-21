#include <bits/stdc++.h>
using namespace std;
int n, m;
string a[100], b[100];
bool check(int i, int j)
{
    if ((n - i) < m || (n - j) < m)
    {
        return false;
    }
    for (int ax = i, bx = 0; bx < m; ax++, bx++)
    {
        for (int ay = j, by = 0; by < m; ay++, by++)
        {
            if (a[ax][ay] != b[bx][by])
                return false;
        }
    }
    return true;
}
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
    if (m > n)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == b[0][0])
            {
                if (check(i, j))
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
