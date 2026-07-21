#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  long long ans = 0;
  int maxr = N / R;
  int maxg = N / G;
  //int maxb = N / B;
  for(int r=0; r <= maxr; r++){
    for(int g=0; g <= maxg; g++){
      if((N - r*R - g*G) >= 0 && (N - r*R - g*G) % B == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
