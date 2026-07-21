#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ll longINF=3e18;
const double eps=1e-8;
const double dinf=190.0;
const double pi=acos(-1);
const int INF=2e9+1;

ll n,a[200005],s[200005],res=longINF;
        
int main() 
{        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        cin>>n>>a[0];
        s[0]=a[0];
        for (int i=1;i<n;i++) {
                cin>>a[i];
                s[i]=s[i-1]+a[i];
        }
        for (int i=0;i<n-1;i++) 
                res=min(res,abs(s[i]-(s[n-1]-s[i])));
        cout<<res;
        return 0;
}
