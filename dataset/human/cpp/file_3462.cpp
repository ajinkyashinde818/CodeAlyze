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
  ll n;
  cin>>n;
  ll A[n];
  ll ans=0;
  ll mi=0;
  ll on=1000000001,tmp;
  for(int i=0;i<n;i++){
    cin>>A[i];
    tmp=A[i];
    if(A[i]<0) mi++;
    if(on>abs(tmp)) on=abs(tmp);
  }
  for(int i=0;i<n;i++) ans+=abs(A[i]);
  if(mi%2)ans-=abs(on)*2;
  cout<<ans;
  return 0;
}
