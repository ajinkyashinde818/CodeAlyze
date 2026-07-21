#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == 'W' || s[2*n-1] == 'W')
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> lr(2*n); // -1 : L, 1 : R
    lr[0] = -1;
    int lcount = 1;
    ll ans = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1]) lr[i] = -1 * lr[i-1];
        else lr[i] = lr[i-1];

        if(lr[i] == -1) 
        {
            lcount++;
        }
        else
        {
            ans = ans * lcount % MOD;
            lcount--;
        }
    }
    if(lcount != 0)
    {
      cout << 0 << endl;
      return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        ans = ans * i % MOD;
    }
    cout << ans << endl;
}
