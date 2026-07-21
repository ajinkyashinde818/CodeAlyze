#include <bits/stdc++.h>
using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> B >> G >> N;

  int ans = 0;
  for(int r=0; r*R<=N; r++){
    for(int g=0; g*G+r*R<=N; g++){
      if((N-g*G-r*R) % B == 0) ans++;
    }
  }
  cout << ans << endl;
}
