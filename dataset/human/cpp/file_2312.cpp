#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

typedef long long ll;

using namespace std;

int main()
{
    ll nc = 0;
    ll zc = 0;

    ll n;
    cin >> n;

    vector<ll> as(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> as[i];
    }

    for (ll i = 0; i < n; i++)
    {
        if (as[i] == 0)
        {
            zc++;
        }
        else if (as[i] < 0)
        {
            as[i] *= -1;
            nc++;
        }
    }

    if (zc > 0 || nc % 2 == 0)
    {
        cout << accumulate(as.begin(), as.end(), 0LL) << endl;
    }
    else
    {
        cout << accumulate(as.begin(), as.end(), 0LL) - 2 * *min_element(as.begin(), as.end()) << endl;
    }

    return 0;
}
