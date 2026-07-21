#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int pivot = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[pivot]) >= abs(a[i]))
            pivot = i;
    }

    int l_minus = 0;
    for (int i = 0; i < pivot; i++)
    {
        if (a[i] < 0)
        {
            l_minus += 1;
            a[i] = abs(a[i]);
        }
    }
    if (l_minus % 2 == 1)
        a[pivot] *= -1;

    int r_minus = 0;
    for (int i = pivot + 1; i < n; i++)
    {
        if (a[i] < 0)
        {
            r_minus += 1;
            a[i] = abs(a[i]);
        }
    }
    if (r_minus % 2 == 1)
        a[pivot] *= -1;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
