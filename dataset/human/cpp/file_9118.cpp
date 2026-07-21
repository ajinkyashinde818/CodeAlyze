#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin>>n>>m;
  vector<string> as(n),bs(m);
  for(int i=0;i<n;i++){cin>>as.at(i);}
  for(int i=0;i<m;i++){cin>>bs.at(i);}
  for(int i=0;i<n+1-m;i++){
    for(int j=0;j<n+1-m;j++){
      int matches=0;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(as.at(i+k).at(j+l)==bs.at(k).at(l)){matches++;}
        }
      }
      if(matches==m*m){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}
