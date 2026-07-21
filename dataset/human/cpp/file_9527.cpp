#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, M; cin >> N >> M;
  
  char tableA[N][N]; char tableB[M][M];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tableA[i][j];
    }
  }
  
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tableB[i][j];
    }
  }
  
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      
      bool flag = true;
      
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          
          if (tableA[i + k][j + l] != tableB[k][l]) flag = false;
          
        }
      }
      
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
      
    }
  }
  
  cout << "No" << endl;
  
}
