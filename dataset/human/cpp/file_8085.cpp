#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

int main(){
  ll N;cin>>N;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];

  // SORT(a);

  vector<ll> sum(N-1);
  sum[0] = a[0];
  rep(i,N-2){
    sum[i+1] = sum[i] + a[i+1];
  }
  ll s = sum[N-2] + a[N-1];
  // cout<<s<<endl;


  ll right, left;
  rep(i,N-1){
    sum[i] -= s - sum[i];
    sum[i] = abs(sum[i]);
  }

  SORT(sum);
  cout<<sum[0]<<endl;

}
