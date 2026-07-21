#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  int m,n;
  cin >> n >> m;
  vector<string> a(n),b(m);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  for(int i=0;i<m;i++) {
    cin >> b[i];
  }
  for(int h=0;h<=n-m;h++) {
    for(int w=0;w<=n-m;w++) {
      bool flag=true;
      for(int i=h;i<h+m;i++) {
        for(int j=w;j<w+m;j++) {
          if(a[i][j]!=b[i-h][j-w]) {
            flag=false;
            break;
          }
        }
      }
      if(flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
