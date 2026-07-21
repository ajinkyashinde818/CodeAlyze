#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for(int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  bool b = true;
  bool bb = false;
  for(int i = 0; i < N-M+1; i++) {
    for(int j = 0; j < N-M+1; j++) {
      b = true;
      for(int k = 0; k < M; k++) {
        for(int l = 0; l < M; l++) {
          if(B.at(k).at(l) != A.at(k+i).at(l+j)) {
          b = false;
          continue;
          }
        }
      }
      if(b) {
        bb = true;
        break;
      }
    }
  }
  if(bb) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}
