#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,n) for(ll i=0;i<(int)(n);i++)
const ll inf=1e9+7;

int main(){
  ll n,sum=0;
  cin>>n;
  ll a[100000];
  rep(i,n){
    cin>>a[i];
  }

  bool flag=false;
  ll mixi=inf,nega=0;
  rep(i,n){
    if(a[i]==0) flag=true;
    if(a[i]<0) nega++;

    if(mixi>abs(a[i])) mixi=abs(a[i]);
  }

  if(flag){
    rep(i,n) sum+=abs(a[i]);
    cout<<sum<<endl;
  }
  else if(nega%2){
    rep(i,n) sum+=abs(a[i]);
    cout<<sum-2*mixi<<endl;
  }
  else{
    rep(i,n) sum+=abs(a[i]);
    cout<<sum<<endl;
  }
}
