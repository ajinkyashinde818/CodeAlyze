#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<deque>
#include <chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const ll E=1e17+7;
#define F first
#define S second
#define MK make_pair
typedef pair<ll,ll> sushi;

ll dp[110000][2][2]={};

int main(){
    ll n,c;
    cin>>n>>c;
    vector<sushi> s;
    for(int i=0;i<n;i++){
        ll x,v;
        cin>>x>>v;
        s.push_back({x,v});
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i].S;
        dp[i][0][0]=sum-s[i].F;
        dp[i][0][1]=dp[i][0][0]-s[i].F;
    }
    ll mx[2]={};
    for(int i=0;i<n;i++){
        mx[0]=max(mx[0],dp[i][0][0]);
        mx[1]=max(mx[1],dp[i][0][1]);
        dp[i][0][0]=mx[0];
        dp[i][0][1]=mx[1];
    }
    sum=0;
    for(ll i=n-1;i>=0;i--){
        sum+=s[i].S;
        dp[i][1][0]=sum-(c-s[i].F);
        dp[i][1][1]=dp[i][1][0]-(c-s[i].F);
    }
    mx[0]=0;
    mx[1]=0;
    for(ll i=n-1;i>=0;i--){
        mx[0]=max(mx[0],dp[i][1][0]);
        mx[1]=max(mx[1],dp[i][1][1]);
        dp[i][1][0]=mx[0];
        dp[i][1][1]=mx[1];
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans=max(ans,dp[i][0][0]+dp[i+1][1][1]);
        ans=max(ans,dp[i][0][1]+dp[i+1][1][0]);
    }
    ans=max(ans,dp[n-1][0][0]);
    ans=max(ans,dp[0][1][0]);
    cout<<ans<<endl;
    
    return 0;
}
