#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  bool jubge = true,ans = false;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  vector<string> b(m);
  for(int i = 0; i < m; i++){
    cin >> b.at(i);
  }
  for(int ni = 0; ni <= n - m; ni++){
    for(int nj = 0; nj <= n - m; nj++){
      jubge = true;
      for(int mi = 0; mi < m; mi++){
        for(int mj = 0; mj < m; mj++){
          if(!(a.at(ni + mi).at(nj + mj) == b.at(mi).at(mj))){
            jubge = false;
          }
        }
        if(!(jubge)){
          break;
        }
      }
      if(jubge){
        ans = true;
        break;
      }
    }
    if(ans){
      break;
    }
  }
  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
