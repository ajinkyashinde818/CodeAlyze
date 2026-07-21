#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<string> a(n),b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  int cnt=0;
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      int ans=0;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l])ans++;
        }
      }
      if(ans==0)cnt++;
    }
  }
  if(cnt==0)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
