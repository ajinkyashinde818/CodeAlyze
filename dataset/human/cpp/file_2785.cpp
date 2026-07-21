#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
ll a[100010];
ll dp[100010];
int main()
{
    ll minst = -mod;
    int n;
    cin>>n;
    int ans1=0;
    ll sum = 0;
    ll ans = 0x3f3f3f3f;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            ans1++;
        } 
        sum+=abs(a[i]);
        ans=min(ans,abs(a[i]));
    }
    if(ans1%2)
    {
        sum-=2*ans;
    }
    cout<<sum<<endl;
    return 0;
}
