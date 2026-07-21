#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ret = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (R * i + G * j > N)
                continue;
            int sum = N - R * i - G * j;
            if (sum % B == 0)
            {
                int cnt = sum / B;
                if (0 <= cnt)
                    ret++;
            }
        }
    }
    cout << ret << endl;
}
