#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> units(3);
    cin >> units[0] >> units[1] >> units[2] >> N;
    std::sort(units.begin(), units.end());
    std::reverse(units.begin(), units.end());

    int count = 0;
    for (int i1 = 0, n1 = N / units[0]; i1 <= n1; ++i1)
    {
        for (int rem23 = N - i1 * units[0]; rem23 >= 0; rem23 -= units[1])
        {
            if (rem23 % units[2] == 0)
            {
                ++count;
            }
        }
    }
    cout << count;

    return 0;
}
