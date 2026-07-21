#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<sstream>
#include<list>
#include<climits>

using namespace std;
#define rep(i,i0,n) for(int i=(i0);i<(int)(n);++i)
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vii;
typedef long long ll;

ll a[100010],b[100010],d[100010];
int n;
ll c;
ll x[100010];
int v[100010];

ll solve(){
    rep(i,0,n)a[i]= i>0? v[i]+a[i-1]:v[i];
    for(int i=n-1;i>=0;i--)b[i] = i<n-1 ? v[i]+b[i+1]: v[i];
    d[n-1] = b[n-1] - (c-x[n-1]);
    for(int i=n-2;i>=0;i--){
        d[i] = b[i] - (c-x[i]);
        d[i] = max(d[i],d[i+1]);
    }
    ll ans = 0;
    rep(l,0,n){
        ll sum = a[l] -  x[l];
        ans = max(ans, sum);
        sum -= x[l];
        if(l < n-1){
            sum += d[l+1];
            ans = max(ans, sum);
        }
    }
    return ans;
}


int main(){
    cin>>n>>c;
    rep(i,0,n)cin>>x[i]>>v[i];
    ll ans=solve();
    reverse(v,v+n);
    rep(i,0,n)x[i]=c-x[i];
    reverse(x,x+n);
    ans = max(ans, solve());
    cout<<ans<<endl;
	return 0;
}
