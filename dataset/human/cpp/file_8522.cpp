#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> pic1(n), pic2(m);
  for(int i=0; i<n; ++i) cin >> pic1[i];
  for(int i=0; i<m; ++i) cin >> pic2[i];
  for(int i1=0; i1<n-m+1; ++i1) for(int i2=0; i2<n-m+1; ++i2){
    bool ansis = true;
    for(int j1=0; j1<m; ++j1){
      for(int j2=0; j2<m; ++j2){
        if(pic1[i1+j1][i2+j2] != pic2[j1][j2]){
          ansis = false;
          break;
        }
      }
      if(!ansis) break;
    }
    if(ansis){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
