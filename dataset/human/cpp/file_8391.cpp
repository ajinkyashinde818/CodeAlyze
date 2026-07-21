#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    char a[n][n],b[m][m];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            bool flag = true;
            for(int k = 0;k < m && flag;k++)
            {
                for(int l = 0;l < m;l++)
                {
                    if(a[i + k][j + l] != b[k][l])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}
