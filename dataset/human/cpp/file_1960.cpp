#include <bits/stdc++.h>

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;

int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += abs(a[i]);
        if (a[i] < 0)
            cnt++;
    }

    if (cnt % 2 == 1)
    {
        sort(a.begin(), a.end());
        for (int i = 0;; i++)
        {
            if (a[i] >= 0 || i == a.size() - 1)
            {
                ans -= 2 * min(abs(a[i]), abs(a[i - 1]));
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
