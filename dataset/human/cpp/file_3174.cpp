#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, cnt = 0, ans = 0, minA = 1e10;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        if (A[i] < 0)
        {
            cnt++;
            A[i] = abs(A[i]);
        }

        ans += A[i];
        minA = min(minA, A[i]);
    }

    if (cnt % 2 == 1)
    {
        cout << ans - 2 * minA << endl;
    }

    else
    {
        cout << ans << endl;
    }
}
