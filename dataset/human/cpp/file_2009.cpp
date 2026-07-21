#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    vll A(N);
    for(ll i=0;i<N;i++)cin>>A[i];
    
    vvll dp(N,vll(2));//j=0,not changed
    
    for(ll i=0;i<N;i++){
        if(i==0){
            dp[i][0]=A[i];
            dp[i][1]=-A[i];
        }else if(i==N-1){
            dp[i][0]=max(dp[i-1][0]+A[i],dp[i-1][1]-A[i]);
        }else{
            dp[i][0]=max(dp[i-1][0]+A[i],dp[i-1][1]-A[i]);
            dp[i][1]=max(dp[i-1][0]-A[i],dp[i-1][1]+A[i]);
        }
    }
    //for(int i=0;i<N;i++)printf("%lld,%lld\n",dp[i][0],dp[i][1]);
    
    cout<<dp[N-1][0]<<endl;
    
    return 0;
}
