#include <bits/stdc++.h>
using namespace std;

int main(){
  long r , g , b, n ;
  cin >> r >> g >> b >> n;
  long ans = 0;
  long t = 0;
  for(long i = 0; r * i <= n ; i++){
      for(long j = 0 ; (r * i + g * j) <= n ; j++ ){
          if( (n - (r * i + g * j)) % b == 0){
              ans += 1;
          }
      }
  }
  cout << ans << endl;
  return 0;
}
