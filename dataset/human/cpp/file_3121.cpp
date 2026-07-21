#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    vll a(n);
    int tmp=inf;int m;ll ans=0;
    rep(i,n){
        cin>>a[i];
        if(abs(a[i])<tmp){
            tmp=abs(a[i]);
            m=i;
        }
        ans+=abs(a[i]);
    }
    rep(i,m){
        if(a[i]<0){
            a[i]*=-1;
            a[i+1]*=-1;
        }
    }
    for(int i=n-1;i>m;i--){
        if(a[i]<0){
            a[i]*=-1;
            a[i-1]*=-1;
        }
    }
    if(a[m]<0)ans+=2*a[m];
    cout<<ans<<endl;
}
