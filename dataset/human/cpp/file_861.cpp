#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  int pat = 0;
  int lima = N/A;
  for (int i = 0; i <= lima; i++) {
    int rest = N-i*A;
    int limb = rest/B;
    for (int j = 0; j <= limb; j++) {
      int r = rest-j*B;
      if (r%C == 0) pat+= 1;
    }
  }
  
  cout << pat << endl;
}
