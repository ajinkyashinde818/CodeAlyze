#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (size_t i = 0; i < n - 1; i += 2)
    {
        if (a[i] < 0)
        {
            if (a[i + 1] < 0 || a[i + 1] < -a[i])
            {
                a[i] = -a[i];
                a[i + 1] = -a[i + 1
                ];
            }
        }
    }

    long long sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << sum << endl;
}
