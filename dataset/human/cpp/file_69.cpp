#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int r = 0; r <= N; r++)
    {
        for (int g = 0; g <= N; g++)
        {
            double b = (double)(N - R * r - G * g) / B;
            if (b - (int)b == 0 && b <= N && b >= 0)
            {
                // cout << r << ' ' << g << ' ' << (int)b << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
