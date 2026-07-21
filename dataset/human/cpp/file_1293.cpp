#include <bits/stdc++.h>
using namespace std;
long long int n,ans;


int main(){

  int r,g,b,n;
  int ans=0;
  
  cin >> r >> g >> b >> n;
  
  for( int i=0; i<=n; i++){
    for( int j=0; j<=n; j++){
      //cout << i*r+j*g << endl;
      if( i*r + g*j <= n && (n - i*r - j*g)%b == 0) ans++;
    }
  }
  
  cout << ans << endl;
  return 0;
}
