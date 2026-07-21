#include <iostream>
using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for(int i = 0; i <= N/R ; ++i){
    for(int j = 0; j <= N/G; ++j){
      if(i*R+j*G > N) break;
      int d = (N - i*R - j*G);
      if(d%B) continue;
      ++ans;
      //cerr << i << " " << j << " " << k << endl;
    }
  }
  cout << ans << endl;
}
