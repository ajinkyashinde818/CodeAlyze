#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,m;
  cin >> n >> m;
  vector<string> a(n),b(m);
  for(int i=0;i<n;++i){
    cin >> a[i];
  }
  for(int i=0;i<m;++i){
    cin >> b[i];
  }
  if(n<m){
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<n-m+1;++i){
    for(int j=0;j<n-m+1;++j){
      bool ha=true;
      for(int x=0;x<m;++x){
        for(int y=0;y<m;++y){
          if(b[x][y]!=a[x+i][y+j]){
            ha=false;
            break;
          }
        }
      }
      if(ha==true){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
