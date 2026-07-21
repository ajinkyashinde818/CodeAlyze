#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int c,tt;
  c=0;
  std::vector<string> a(n),b(m);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  for(int i=0;i<n-m+1&&c==0;i++){
    for(int j=0;j<n-m+1&&c==0;j++){
      tt=0;
      for(int k=0;k<m&&c==0;k++){
        for(int l=0;l<m&&c==0;l++){
          if(b[k][l]==a[i+k][j+l])tt++;
          if(tt==m*m)c=1;
        }
      }
    }
  }
  if(c)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
