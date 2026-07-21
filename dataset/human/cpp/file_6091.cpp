#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n,c; cin>>n>>c;
  vector<long long> x(n),v(n),y(n),w(n,0);
  for(int i=0; i<n; ++i) cin>>x[i]>>v[i];
  for(int i=0; i<n; ++i){ y[i]=c-x[n-i-1]; w[i]=v[n-i-1];}
  for(int i=0; i<n; ++i){ v[i]-=x[i]; w[i]-=y[i]; if(i>0){ v[i]+=v[i-1]+x[i-1]; w[i]+=w[i-1]+y[i-1];}}
  vector<long long> p(n,v[0]),q(n,w[0]);
  for(int i=1; i<n; ++i){ p[i]=max(p[i-1],v[i]); q[i]=max(q[i-1],w[i]);}
  long long res=0;
  res=max(res,max(p[n-1],q[n-1]));
  for(int i=0; i<n-1; ++i) res=max(res,max(v[i]+q[n-i-2]-x[i],w[i]+p[n-i-2]-y[i]));
  cout<<res<<endl;
  return 0;
}
