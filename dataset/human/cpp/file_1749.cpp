#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  Int k=0;
  while(k*(k-1)/2<n) k++;
  if(k*(k-1)/2!=n){
    cout<<"No"<<endl;
    return 0;
  }
  
  cout<<"Yes"<<endl;
  cout<<k<<endl;
  vector<vector<Int> > G(k);

  Int pos=0;
  for(Int i=0;i<k;i++){
    for(Int j=1;j<k-i;j++){
      //cout<<i+j<<":"<<k<<endl;
      G[i].emplace_back(pos);
      G[i+j].emplace_back(pos);
      pos++;
    }    
  }
  
  for(Int i=0;i<k;i++){
    cout<<k-1;
    for(Int x:G[i]) cout<<" "<<x+1;
    cout<<endl;
  }
  return 0;
}
