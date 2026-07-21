#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Yes" << endl << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 1";
        return 0;
    }
    for (int il = 2; il <= n; ++il)
    {
        if ((1 + (il - 1)) * (il - 1) / 2 == n)
        {
            cout << "Yes" << endl << il << endl;
            vector< vector<int> > a(il);
            int nr = 1;
            for (int i = 0; i < il - 1; ++i)
            {
                for (int j = i + 1; j < il; ++j)
                {
                    a[i].push_back(nr);
                    a[j].push_back(nr);
                    ++nr;
                }
            }
            for (int i = 0; i < il; ++i)
            {
                cout << a[i].size() << " ";
                for (int j = 0; j < a[i].size(); ++j)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}
