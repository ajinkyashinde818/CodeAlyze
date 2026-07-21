#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    ll minim = 1 << 30;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp = a[i];
        if (temp < 0)
        {
            sum += -temp;
            cnt++;
        }
        else
        {
            sum += temp;
        }
        minim = min(minim, abs(a[i]));
    }

    ll ans = 0;
    if (0 == cnt % 2)
    {
        ans = sum;
    }
    else
    {
        ans = sum - minim * 2;
    }

    cout << ans << endl;
    return 0;
}
