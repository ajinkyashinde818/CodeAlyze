#include <iostream>
#include <string>
using namespace std;

void solve(){
  int n, m; cin >> n >> m;
  string sn[n], sm[m];
  for(int i = 0; i < n; ++i) cin >> sn[i];
  for(int i = 0; i < m; ++i) cin >> sm[i];
  for(int i = 0; i < n-m+1; i++){
    for(int j = 0; j < n-m+1; j++){
      int flag = 1;
      int cnt = 0;
		for(int k = 0; k < m && flag; k++){
          if(sn[i+k].substr(j, m) != sm[k]) flag = 0;
          else cnt++;
        }
      if(cnt == m) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

int main(){
  solve();
  return 0; 
}
