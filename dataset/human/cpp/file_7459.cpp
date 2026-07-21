#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a, subsum[200001];
    for (long long i = 1; i <= n; i++)
    {
        cin >> a;
        if (i == 1)
            subsum[1] = a;
        else
            subsum[i] = subsum[i - 1] + a;
    }
    long long ans = 2e9;
    for (long long i = 1; i <= n - 1; i++)
    {
        long long tmp = subsum[n] - subsum[i];
        long long a = abs(subsum[i] - tmp);
        if (ans > a)
        {
            ans = a;
        }
    }
    cout << ans << endl;
    return 0;
}
