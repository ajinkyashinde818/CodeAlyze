#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;

#define INF 1e+9
#define MAX_V 300

struct edge {
    int to;
    int cost;
};
using P = pair<ll, ll>;
int main(){
  ll n;cin>>n;
  VL a(n);REP(i,n){cin>>a[i];}
  ll sum=0;
  ll count=0;
  int key=0;
  for(int i=0;i<n;i++){
    if(a[i]<0){
      count++;
    }
  }
  ll min=10000000000000;
  for(int i=0;i<n;i++){
    if(a[i]==0){
      key=1;
    }
  }
  if(key==1||count%2==0){
    for(int i=0;i<n;i++){
      if(a[i]<0){
        a[i]=-a[i];
      }
      sum+=a[i];
    }
  }else{
    for(int i=0;i<n;i++){
      if(min>abs(a[i])){
        min=abs(a[i]);
      }
      if(a[i]<=0){
        a[i]=-a[i];
      }
      sum+=a[i];
    }
    sum-=2*min;
  }
  cout<<sum<<endl;
}
