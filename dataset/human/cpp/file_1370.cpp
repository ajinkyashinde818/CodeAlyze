#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int R, G, B, N;
ll ans;

int main()
{
    cin >> R >> G >> B >> N;
    for (int i = 0; R * i <= N; i++)
    {
        for (int j = 0; G * j <= N; j++)
        {
            if (R * i + G * j > N)
                continue;
            int res = N - i * R - G * j;
            if (res % B == 0)
                ans++;
        }
    }
    cout << ans << endl;
}
