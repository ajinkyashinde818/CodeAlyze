#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int ans;
  ans = 0;
  int r, g, b, N;
  cin >> r >> g >>  b >> N;
  
  for(int i = 0; i * r <= N; i++){
    for(int j = 0; j * g <= N - i*r; j++){
      if((N - i*r - j*g) % b == 0)ans++;
    }
  }
  
  cout << ans << endl;
}
