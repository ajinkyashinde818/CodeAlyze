#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  Int neg=0;
  for(Int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]<0) neg++,a[i]*=-1;
  }
  sort(a.begin(),a.end());
  Int sum=0;
  for(Int i=0;i<n;i++) sum+=a[i];
  neg%=2;
  if(neg) sum-=a[0]*2;
  cout<<sum<<endl;
  return 0;
}
