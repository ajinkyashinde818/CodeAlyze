#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
ll n;
string s;
ll a[200005];
ll ans = 1;
ll cnt = 0;
ll cnt2 = 0;


int main()
{
    cin>>n>>s;
    for(ll i = 0; i < s.size(); i++)
    {
        bool v = false;
        if(s[i] == 'B') v = true;
        if(v ^ (cnt % 2)) cnt++, a[i] = 1;
        else cnt--, a[i] = -1;
        if(cnt < 0)
        {
            printf("0\n");
            return 0;
        }
    }
    if(cnt != 0)
    {
        printf("0\n");
        return 0;
    }
    for(ll i = 0; i < s.size(); i++)
    {
        if(a[i] == -1) ans *= cnt2, cnt2--;
        else cnt2++;
        ans %= M;
    }
    for(ll i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= M;
    }
    cout<<ans<<endl;
    return 0;
}
