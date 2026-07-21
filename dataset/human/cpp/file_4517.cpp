#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b)a=b;};
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b)a=b;};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int t,d;
  Int ta,tb,da,db;
  cin>>t>>d>>ta>>tb>>da>>db;

  using D = double;
  D ans=1e18;
  for(Int i=0;i<=d;i++){
    for(Int j=0;j<=d;j++){
      Int v=i*da+j*db;
      if(v==0||v>d) continue;
      Int sm=ta*(i*da)+tb*(j*db);
      chmin(ans,abs(t-(D)sm/v));
    }
  }
  
  cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
