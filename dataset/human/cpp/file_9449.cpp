#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> mpN(N,vector<int>(N,0));
  vector<vector<int>> mpM(M,vector<int>(M,0));
  
  string p;
  
  for (int i=0; i<N; i++) {
    cin >> p;
    for (int j=0; j<N; j++) {
      if (p[j] == '#') {
        mpN[i][j]++;
      }
    }
  }
  for (int i=0; i<M; i++) {
    cin >> p;
    for (int j=0; j<M; j++) {
      if (p[j] == '#') {
        mpM[i][j]++;
      }
    }
  }
  
  bool br = false;
  
  for (int i=0; i<N-M+1; i++) {
    for (int j=0; j<N-M+1; j++) {
      for (int k=0; k<M; k++) {
        for (int l=0; l<M; l++) {
          if (mpM[k][l] != mpN[i+k][j+l]) {
            br = true;
            break;
          }
        }
        if (br) {
          br = false;
          break;
        }
        if (k == M-1) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  
  return 0;
}
