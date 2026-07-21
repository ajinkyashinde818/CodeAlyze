#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,j,k,l;
  bool f;
  cin>>n>>m;
  vector<string> a(n),b(m);
  for(i=0;i<n;i++) cin>>a.at(i);
  for(i=0;i<m;i++) cin>>b.at(i);
  for(k=0;k<=n-m;k++){
    for(l=0;l<=n-m;l++){
      f=true;
      for(i=0;i<m;i++){
        for(j=0;j<m;j++){
          if(a.at(i+k).at(j+l)!=b.at(i).at(j)){
            f=false;
            break;
          }
        }
        if(f==false) break;
      }
      if(f==true){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
    
}
