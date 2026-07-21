#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    bool jest = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i + m - 1 < n && j + m - 1 < n)
            {
                bool db = true;
                for (int k = 0; k < m; ++k)
                    for (int l = 0; l < m; ++l)
                        if (a[i + k][j + l] != b[k][l])
                            db = false;
                if (db)
                    jest = true;
            }
        }
    }
    if (jest)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
