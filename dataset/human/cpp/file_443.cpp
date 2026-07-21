#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N; 
  cin >> R >> G >> B >> N;
  int ans = 0;
  for(int r = 0; r <= N; r++){
    for(int g = 0; g <= N-r*R; g++){
      int b = r*R + g*G;
      if( b <= N && (N-b)%B == 0) ans++;
    }
  }
  cout << ans << endl;
}
