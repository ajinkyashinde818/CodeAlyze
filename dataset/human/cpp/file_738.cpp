#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N, count = 0;
  cin >> R >> G >> B >> N;
  
  for (int i = 0; i <= N/R; i++) {
    for (int j = 0; j <= (N-i*R)/G; j++) {
      if ((N-i*R-j*G) % B == 0)
        count++;
    }
  }
  
  cout << count << endl;  
}
