#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

/*
   cin.tie(0);
   ios::sync_with_stdio(false);
   */

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  ll n,c;
  cin>>n>>c;
  vll x(n),v(n);
  rep(i,n){
    cin>>x[i]>>v[i];
  }
  vll r(n),l(n);
  rep(i,n){
    if(i==0){
      r[i]=v[i];
      l[n-i-1]=v[n-1];
    }else{
      r[i]=r[i-1]+v[i];
      l[n-i-1]=l[n-i]+v[n-i-1];
    }
  }

  vll R(n),L(n);
  ll ans=-LINF;
  rep(i,n){
    ans=max(ans,max(r[i]-x[i],l[n-i-1]-(c-x[n-i-1])));
    R[i]=r[i]-x[i];
    r[i]-=(x[i]*2);
    L[n-i-1]=l[n-i-1]-(c-x[n-i-1]);
    l[n-i-1]-=(c-x[n-i-1])*2;
  }
  REP(i,1,n){
    r[i]=max(r[i],r[i-1]);
    R[i]=max(R[i],R[i-1]);
    l[n-i-1]=max(l[n-i-1],l[n-i]);
    L[n-i-1]=max(L[n-i-1],L[n-i]);
  }
  
  ans=max(ans,l[0]);
  REP(i,0,n-1){
    ans=max(ans,r[i]+L[i+1]);
  }
  REP(i,1,n){
    ans=max(ans,l[i]+R[i-1]);
  }
  cout<<max(ans,(ll)0)<<endl;
  return 0;
}
