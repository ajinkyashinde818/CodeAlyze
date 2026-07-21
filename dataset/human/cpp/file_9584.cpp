#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  for(int i=0;i<n;i++) cin >> a.at(i);
  for(int i=0;i<m;i++) cin >> b.at(i);
  
  int ans=0;
  
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      int k=1;
      for(int y=0;y<m;y++){
        for(int x=0;x<m;x++){
          k*=(a.at(y+i).at(x+j)==b.at(y).at(x));
        }
      }
      ans+=k;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
