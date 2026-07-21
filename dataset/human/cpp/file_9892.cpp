#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <set>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define INF 1LL << 59
using ld = long double;

const int MAX = 510000;

ll dp[100010][4];

ll pow_mod(ll n, ll x)
{
    ll res = 1;
    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            res *= x;
            res %= MOD;
        }
        x = x * x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}
int alph[26];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //cout << fixed << setprecision(5);

    int N;
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i)
    {
        alph[s[i] - 'a']++;
    }

    ll t = 1;
    for (int i = 0; i < 26; ++i)
    {
        t *= (alph[i]+1);
        t %= MOD;
    }

    cout << t - 1 << endl;

    return 0;
}
