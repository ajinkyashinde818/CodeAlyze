#include <iostream>
using namespace std;
 
int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i=0; i<=3001-R; ++i) {
    for (int j=0; j<=3001-G; ++j) {
      int diff = N - (i*R + j*G);
      if ((diff>=0)&&(diff%B==0)) {
          ++ans;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
