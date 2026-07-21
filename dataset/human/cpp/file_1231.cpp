#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int r,g,b,n;
  cin>>r>>g>>b>>n;
  Int ans=0;
  for(Int i=0;i<=n;i++){
    for(Int j=0;j<=n;j++){
      Int k=(n-(r*i+g*j))/b;
      if(0<=k&&k<=n)
        if((r*i+g*j+b*k)==n) ans++;      
    }
  }
  cout<<ans<<endl;
  return 0;
}
