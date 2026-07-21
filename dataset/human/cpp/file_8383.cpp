#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<string> a(N),b(M);
  for(int i=0;i<N;i++)cin>>a.at(i);
  for(int i=0;i<M;i++)cin>>b.at(i);
  
  int flag=0,ans=0;
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      if(a.at(i).substr(j,M)==b.at(0)){
        flag=0;
        for(int k=0;k<M;k++){
          if(a.at(i+k).substr(j,M)!=b.at(k)){
            flag++;
            break;
          }
        }
        if(flag==0)ans++;
      }
    }
  }
  if(ans==0)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
