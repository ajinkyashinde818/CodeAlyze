#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(double i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int const INF = 1000000;
int long long  const  INFLL = 10000000000;
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> rui(n+1);
    rui[0]=0;
    ll sum=0;
    
    rep(i,n){
        cin>>v[i];
        rui[i+1]=rui[i]+v[i];
        sum+=v[i];
    }
    ll ansmin=INFLL;
    for(int i=1;i<=n-1;i++){
        ll sunuke=rui[i];
        ll arai=sum-sunuke;
        ll sa=abs(sunuke-arai);
        ansmin=min(ansmin,sa);
        
    }
    cout<<ansmin<<endl;
    
    
    
    return 0;
}
