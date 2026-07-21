#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    int /*my,mx,*/c=0;
    for (int ny = 0; ny < n; ny++)
    {
        for (int nx = 0; nx < n; nx++)
        {
            for (int my = 0; my < m; my++)
            {
                for (int mx = 0; mx < m; mx++)
                {   
                    if(a[ny+my][nx+mx]==b[my][mx]) c++;
                }
            }
            if(c==m*m) 
            {
                cout << "Yes" << endl;
                return 0;
            }
            /*cout << ">>>" << 'n' << ny+my << ',' << nx+mx << '|' << 'm' << my << ',' << mx << ':' << a[ny+my][nx+mx] << '|' << b[my][mx] << "C=" << c << endl;*/
            c = 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
