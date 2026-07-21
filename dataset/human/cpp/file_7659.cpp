#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    long long a;
    long long cumlative_sum[N + 1] = {};
    for (int i = 1; i <= N; i++)
    {
        cin >> a;
        cumlative_sum[i] = cumlative_sum[i - 1] + a;
    }

    long long ans = LONG_LONG_MAX;
    for (int i = 1; i < N; i++)
    {
        long long x = cumlative_sum[i];
        long long y = cumlative_sum[N] - cumlative_sum[i];
        ans = min(ans, abs(x - y));
    }

    cout << ans << endl;
}
