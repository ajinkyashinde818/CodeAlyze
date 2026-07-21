#include <bits/stdc++.h>
using namespace std;

//Bの左上をAの(x,y)に合わせて一致するかを返す関数
bool check(vector<string> &a, vector<string> &b, int y, int x){
  int n = a.size(), m = b.size();
  
  for (int i=0; i<m; i++){
    for (int j=0; j<m; j++){
      if (b.at(i).at(j) != a.at(i+y).at(j+x)){
        return false;
      }
    }
  }
  
  return true;
}

int main() {
  int n, m; cin >>n >>m;
  vector<string> a(n);
  for (int i=0; i<n; i++) cin >> a.at(i);
  vector<string> b(m);
  for (int i=0; i<m; i++) cin >> b.at(i);
  
  int times = n-m+1;
  bool ans = false;
  bool esc = false;
  
  for (int i=0; i<times; i++){
    for (int j=0; j<times; j++){
      if (check(a,b,i,j)){
        ans = true;
        esc = true;
        break;
      }
    }
    if(esc){
      break;
    }
  }
  
  if(ans){
    cout <<"Yes" <<endl;
  }else{
    cout <<"No" <<endl;
  }
}
