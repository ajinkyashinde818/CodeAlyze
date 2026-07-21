#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  
  int answer = 0;
  int max_r = floor(N/R);
  int max_g = floor(N/G);
  int max_b = floor(N/B);
  
  for (int g = 0; g <= max_g; g++){
    for (int b = 0; b <= max_b; b++){
      if((N-b*B-g*G) % R == 0 && (N-b*B-g*G) >= 0){
        answer ++;
        //cout << b << g << endl;
      }
    }
  }
  
  cout << answer << endl;
}
