#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r ,g, b , n;
  int ans = 0;
  cin >> r >> g >> b >> n;
  for(int i = 0; i<=n/r ;i++){
    for(int j = 0 ; j<=n/g ;j++){
      int k ;
      k =  n - r*i - g*j;
      if( k >= 0 && k % b == 0){
        ans += 1;
      }
    }
  }
  cout << ans << endl;
  
}
