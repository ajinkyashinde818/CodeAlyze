#include <bits/stdc++.h>
using namespace std;

int main() {
  int R;
  int G;
  int B;
  int N;
  cin >> R >> G >> B >> N;
  int maxR;
  int maxG;
  int ans = 0;
  maxR = N/R;
  for (int i=0; i<(maxR + 1); i++){
  maxG = (N - i*R)/G;
    for(int j=0; j<(maxG + 1); j++){
     if( (N - i*R -j*G)%B==0){
       ans++;
     }
      
    }
  
  }

  cout << ans << endl;
}
