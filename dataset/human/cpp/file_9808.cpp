#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;

    cin >> N >> S;
    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<long long> v(26);
    long long ans = 1LL;
    const long long MOD = 1e9 + 7;
    for (int i = 0; i < N; i++)
    {
        v[S[i] - 'a']++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            ans *= (v[i] + 1);
            ans %= MOD;
        }
    }

    cout << ans - 1 << endl;

    return 0;
}
