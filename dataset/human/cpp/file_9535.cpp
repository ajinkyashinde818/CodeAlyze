/**
 * @author: shashankchdhry
 * @made:   2020-04-05 11:35:19 
**/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    for (int i = 0; i < n-m+1; i++)
    {
        for (int j = 0; j < n-m+1; j++)
        {
            bool flag = true;
            for (int k = 0; k < m; k++)
                for (int l = 0; l < m; l++)
                    if (a[i+k][j+l] != b[k][l])
                    {
                        flag = false;
                        break;
                    }
            if (flag == true)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";

    return 0;
}
