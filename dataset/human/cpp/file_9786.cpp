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
typedef  int long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,ll> m;
    rep(i,n){
        m[s[i]]++;
    }
    if(n==1){
        cout<<1<<endl;return 0;
    }
    ll ans=1;
    for(auto itr=m.begin();itr!=m.end();itr++){
        ll u=itr->second;
        ans*=(u+1);
        ans%=1000000007;
        
    }
    
    cout<<ans-1<<endl;
return 0;
}
