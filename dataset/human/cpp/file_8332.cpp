#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> a(n),b(m);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<m; i++){
    cin >> b[i];
  }
  bool yes=true;
  for(int i=0; i+m<=n; i++){
    for(int j=0; j+m<=n; j++){
      for(int k=0; k<m; k++){
        if(!yes) continue;
        if(b[k] != a[k+i].substr(j,m)) yes = false;
      }
      if(yes){
        cout << "Yes" << endl;
        return 0;
      }
      yes = true;
    }
  }
  cout << "No" << endl;
  return 0;
}
