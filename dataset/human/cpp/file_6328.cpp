#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    if (S[0] == 'W' || S[2 * N - 1] == 'W')
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> C(2 * N);
    C[0] = 1;
    long long int cnt = 1;
    for (int i = 1; i < 2 * N; i++)
    {
        if (S[i] == S[i - 1])
        {
            C[i] = 1 - C[i - 1];
        }
        else
        {
            C[i] = C[i - 1];
        }
        cnt += (2 * C[i] - 1);
    }
    if (C[2 * N - 1] == 1 || (cnt != 0))
    {
        cout << 0 << endl;
        return 0;
    }
    cnt = 1;
    int cl = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (C[i])
        {
            cl++;
        }
        else
        {
            cnt = cnt * cl % MOD;
            cl--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cnt = cnt * (i + 1) % MOD;
    }
    cout << cnt << endl;
}
