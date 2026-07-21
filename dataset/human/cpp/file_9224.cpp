#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,yes=0;cin>>n>>m;
  vector<string> a(n),b(m);
  for(int i=0;i<n;i++)cin>>a.at(i);
  for(int j=0;j<m;j++)cin>>b.at(j);
  for(int k=0;k<n-m+1;k++){
    for(int l=0;l<n-m+1;l++){
      int x=0;
      for(int p=0;p<m;p++){
        if(a.at(k+p).substr(l,m)!=b.at(p)){
          x++;
          break;
        }
      }
      if(x==0){
        cout<<"Yes"<<endl;
        yes=1;
        break;
      }
    }
    if(yes==1)break;
  }
  if(yes==0)cout<<"No"<<endl;
}
