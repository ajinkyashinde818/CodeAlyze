#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<string>a(n);
  vector<string>b(m);
  int i,j,k,l;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  for(i=0;i<m;i++){
    cin >> b[i];
  }
  int anss = 0;
  int chk = 0;

  for(i=0;i<=n-m;i++){
    for(j=0;j<=n-m;j++){
      if(a[i][j]==b[0][0]){
        chk = 1;
        for(k=0;k<m;k++){
          for(l=0;l<m;l++){
            if(a[i+k][j+l]!=b[k][l])chk=0;
          }
        }
        if(chk==1)anss = 1;
      }
    }
  }
  if(anss==1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
