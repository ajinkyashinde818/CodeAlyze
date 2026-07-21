#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    ll n,c,x[100010],v[100010];
    ll sum[100010]={},sumr[100010]={};
    ll s1[100010]={},s2[100010]={},r1[100010]={},r2[100010]={};
    ll smax[100010]={},rmax[100010]={};
    cin>>n>>c;
    rep(i,n){
        cin>>x[i]>>v[i];
        sum[i+1]=sum[i]+v[i];
    }
    // cout<<endl;
    // rep(i,n+1)         cout<<sum[i]<<endl;
    // cout<<endl;
    repr(i,n){
        sumr[i]=sumr[i+1]+v[i];
        // cout<<sumr[i]<<endl;
    }
    // cout<<endl;
    rep2(i,1,n+1){
        s1[i]=sum[i]-x[i-1];
        s2[i]=sum[i]-x[i-1]*2;
        // cout<<s1[i]<<" "<<s2[i]<<endl;
    }
    // cout<<endl;
    repr(i,n){
        r1[i]=sumr[i]-(c-x[i]);
        r2[i]=sumr[i]-2*(c-x[i]);
        // cout<<r1[i]<<" "<<r2[i]<<endl;
    }
    // cout<<endl;
    rep2(i,1,n+1){
        smax[i]=max(smax[i-1],s1[i]);
        rmax[i]=max(rmax[i-1],r1[n-i]);
        // cout<<smax[i]<<" "<<rmax[i]<<endl;
    }
    // cout<<endl;
    ll ans1=0,ans2=0,ans3=0;
    ans1=max(smax[n],rmax[n]);
    // cout<<ans1<<endl;
    rep2(i,1,n+1){
        ans2=max(ans2,s2[i]+rmax[n-i]);
        // cout<<ans2<<endl;
    }
    // cout<<endl;
    rep(i,n){
        ans3=max(ans3,r2[i]+smax[i]);
        // cout<<ans3<<endl;
    }
    // cout<<endl;
    ans1=max(max(ans2,ans3),ans1);
    cout<<ans1<<endl;
    return 0;
}
