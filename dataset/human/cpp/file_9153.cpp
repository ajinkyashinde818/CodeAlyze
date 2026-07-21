#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n, m; cin >> n >> m;
  vector<string> a(n), b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  for(int i = 0; i <= n - m; i++){
    for(int j = 0; j <= n - m; j++){
      //cout << "i : " << i << " j : " << j << endl;
      int x = 0, sum = 0;
      for(int k = i; k < i + m; k++){
        int y = 0;
        for(int l = j; l < j + m; l++){
          //cout << a[k][l] << " " << b[x][y] << endl;
          if(a[k][l] == b[x][y]) sum++;
          y++;
        }
        x++;
      }
      //cout << sum << endl;
      if(sum == m * m){
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
  return;
}

int main(){
  solve();
  return 0;
}
