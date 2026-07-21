#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n,m;
  cin >> n >> m;
  vector<string> a(n),b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i+m-1 > n or j+m-1 > n) continue;

      bool flag = true;
      for(int y = 0; y < m; y++){
        for(int x = 0; x < m; x++){
          if(a[i+y][j+x] != b[y][x]){
            flag = false;
            y = x = m;
          }
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
