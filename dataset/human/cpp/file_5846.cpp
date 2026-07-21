#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,c;
  cin>>n>>c;
  vector<Int> x(n),v(n);
  for(Int i=0;i<n;i++) cin>>x[i]>>v[i];

  Int ans=0;
  for(Int uku=0;uku<2;uku++){
    vector<Int> s(n+1,0);
    for(Int i=0;i<n;i++) s[i+1]=s[i]+v[i];
    for(Int i=0;i<n;i++) chmax(ans,s[i+1]-x[i]);

    auto calc=[&](Int i){
      return (s[n]-s[i]-(c-x[i])*2);
    };
    
    Int res=calc(n-1);
    for(Int j=n-2;j>=0;j--){
      chmax(res,calc(j+1));
      chmax(ans,res+(s[j+1]-s[0]-x[j]));
    }
    for(Int i=0;i<n;i++) x[i]=c-x[i];
    reverse(x.begin(),x.end());
    reverse(v.begin(),v.end());
  }

  cout<<ans<<endl;
  return 0;
}
