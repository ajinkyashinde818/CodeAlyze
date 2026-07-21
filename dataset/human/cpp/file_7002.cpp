#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VI A(N),B(N);
  rep(i,N) cin>>A[i];
  rep(i,N) cin>>B[i];
  VI X(N);
  int tmp=0;
  int cnt=0;
  int C=0;
  int F=1;
  while(tmp<=N-1){
    if(A[C]!=B[tmp] and X[C]==0){
      X[C]=B[tmp];
      tmp++;
      cnt=0;
    }else{
      cnt++;
    }
    C=(C+1)%N;
    if(cnt>=N){
      F=0;
      break;
    }
  }
  if(F==0){
    reverse(all(B));
    rep(i,N) X[i]=0;
    tmp=0;
    cnt=0;
    C=0;
    F=1;
    while(tmp<=N-1){
      if(A[C]!=B[tmp] and X[C]==0){
        X[C]=B[tmp];
        tmp++;
        cnt=0;
      }else{
        cnt++;
      }
      C=(C+1)%N;
      if(cnt>=N){
        F=0;
        break;
      }
    }
  }
  if(F){
    cout<<"Yes"<<endl;
    rep(i,N) cout<<X[i]<<" ";
    cout<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
