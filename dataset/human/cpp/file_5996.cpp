#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005


ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


/////////////////////////////////////////////////////////////////


int main(){
    ll n,c;cin>>n>>c;
    ll x1[n+2];ll v1[n+1];rep(i,1,n)cin>>x1[i]>>v1[i];x1[0]=0;x1[n+1]=c;v1[0]=0;v1[n+1]=0;
    ll dp1[n+1];dp1[0]=0;
    rep(i,1,n){
        dp1[i]=dp1[i-1]+v1[i]-x1[i]+x1[i-1];
    }
    rep(i,1,n){
        dp1[i]=max(dp1[i-1],dp1[i]);
    }
    //rep(i,0,n)cout<<i<<" "<<dp1[i]<<endl;
    ll ans1=dp1[n];ll pre=0;
    for(int i=n;i>=1;i--){
        pre=pre+v1[i]+x1[i]-x1[i+1];
        ans1=max(ans1,pre);
        ans1=max(ans1,pre+dp1[i-1]-(c-x1[i]));
    }
    
    
    ll x2[n+2];ll v2[n+1];x2[0]=0;x2[n+1]=c;
    rep(i,1,n){
        x2[i]=c-x1[n+1-i];
        v2[i]=v1[n+1-i];
     //   cout<<"x2v2 "<<x2[i]<<" "<<v2[i]<<endl;
    }
    ll dp2[n+1];dp2[0]=0;
    rep(i,1,n){
        dp2[i]=dp2[i-1]+v2[i]-x2[i]+x2[i-1];
    }
    rep(i,1,n){
        dp2[i]=max(dp2[i-1],dp2[i]);
    }
 //   rep(i,0,n)cout<<i<<" "<<dp2[i]<<endl;
    ll ans2=dp2[n];pre=0;
    for(int i=n;i>=1;i--){
        pre=pre+v2[i]+x2[i]-x2[i+1];
      //  cout<<i<<" "<<pre<<endl;
        ans2=max(ans2,pre);
        ans2=max(ans2,pre+dp2[i-1]-(c-x2[i]));
    }
    cout<<max(ans1,ans2)<<endl;
    
    
    return 0;
}
