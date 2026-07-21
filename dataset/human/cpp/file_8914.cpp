#include <iostream>
#include <vector>
#include <string>
#include <complex>

using namespace std;

int n, m;
string A[500], B[500];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    for (int i1 = 0; i1 + m <= n; i1++)
    {
        for (int j1 = 0; j1 + m <= n; j1++)
        {
            int t = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (A[i1 + i][j1 + j] != B[i][j])
                    {
                        t = 1;
                    }
                }
            }
            if (!t) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
