#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5+5;
const ll mod = ll(1e9+7);

char s[maxn];
int s2[maxn];

int main()
{
    int n;
    scanf("%d%s",&n,s);
    s2[0] = 1;
    for(int i=1;i<2*n;i++)
    {
        if(s[i]==s[i-1])
            s2[i] = (s2[i-1]+1)%2;
        else
            s2[i] = s2[i-1];
    }
    ll sum = 1LL;
    for(int i=2;i<=n;i++)
    {
        sum = (sum * (ll)i)%mod;
    }
    //cout << sum << endl;
    int num = 0;
    for(int i=0;i<2*n;i++)
    {
        //out << sum << "*" << num << endl;
        if(s2[i]==1)
            num++;
        else
        {
            sum = (sum * ll(num))%mod;
            //cout << sum << "*" << num << endl;
            num--;
        }
    }
    if(s[0]=='W'||num!=0)
        printf("0\n");
    else
        printf("%lld\n",sum);
    return 0;
}
