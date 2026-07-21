#include <bits/stdc++.h>
using namespace std;

char A[50][50], B[50][50];

bool loop(int x, int y, int m)
{
    for (int i = x; i < x + m; i++)
        for (int j = y; j < y + m; j++)
            if (A[i][j] != B[i - x][j - y])
                return false;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (A[i][j] == B[0][0])
            {
                if (loop(i, j, m))
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
    }
    cout << "No" << endl;
}
