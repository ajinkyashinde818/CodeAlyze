#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include <string>
#include <complex>
#include <functional>
#include <map>
#include <queue>
using namespace std;
using ll = long long;
//typedef pair<string,string> P;
//double dat[100][100];
//int dp[6][1010];//動的計画法
//int prime[100001];
//char str[1010][1010];
//typedef pair<ll,ll> A;
//vector<A> pc;
//int ABS(int a){return max(a,-a);}
int main() {
  int r,g,b,n,ans=0;
  cin>>r>>g>>b>>n;
  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
      int k=(n-(i*r+j*g))/b;
      if(k<0) continue;
      if(i*r+j*g+k*b==n) {
        ans++;
        //cout<<i<<j<<k<<endl;
      }
    }
  }
  cout<<ans;
  return 0;
}
