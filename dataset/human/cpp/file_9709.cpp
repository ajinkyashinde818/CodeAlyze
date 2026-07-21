#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        a[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0;i<26;i++)
        ans=(ans*(a[i]+1))%mod;
    ans=(ans-1)%mod;
    cout<<ans<<"\n";
}
