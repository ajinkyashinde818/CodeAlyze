#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int count = 0;
  int rlim = N / R;
  for (int i = 0; i <= rlim; i++){
    int newN = N - (R * i);
    int glim = newN / G;
    for (int j = 0; j <= glim; j++){
      if ((newN - (G * j)) % B == 0){
        count += 1;
      }
    }
  }
  cout << count << endl;
}
