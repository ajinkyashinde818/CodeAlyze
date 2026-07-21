#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0,R,G,B,N;
  cin >> R >> G >> B >> N;
  for (int i = 0; i < N/R+1; i++){
    if (i*R>N){
      break;
    }
    for (int j = 0; j < N/G+1; j++){
      if (i*R+j*G>N){
        break;
      }
      if (R*i+G*j <= N and (N-R*i-G*j)%B==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
