#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool local_success(const vector<string>& from, const vector<string>& to, const int i, const int j)
{
    const int m = to.size();

    for (int ii = 0; ii < m; ii++)
    {
        for (int jj = 0; jj < m; jj++)
        {
            if (from[i + ii][j + jj] != to[ii][jj])
            {
                return false;
            }
        }
    }
    return true;
}

bool success(const vector<string>& from, const vector<string>& to)
{
    const int n = from.size();
    const int m = to.size();

    for (int i = 0; i + m <= n; i++)
    {
        for (int j = 0; j + m <= n; j++)
        {
            if (local_success(from, to, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> from(n);
    for (auto& v : from)
    {
        cin >> v;
    }
    vector<string> to(m);
    for (auto& v : to)
    {
        cin >> v;
    }

    cout << (success(from, to) ? "Yes" : "No") << endl;
}
