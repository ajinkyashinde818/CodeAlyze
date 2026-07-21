#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
char a[maxn][maxn], b[maxn][maxn];
int main(){
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
  for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) cin >> b[i][j];
  for(int i = 0; i <= n - m; i++) for(int j = 0; j <= n - m; j++){
  	bool bad = false;
    for(int k = 0; k < m; k++) for(int l = 0; l < m; l++){
    	bad |= a[i + k][j + l] != b[k][l];
    }
    if(!bad){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
