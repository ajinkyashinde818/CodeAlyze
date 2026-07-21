#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  int A[N][N], B[M][M];
  char c;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> c;
      if (c=='.') A[i][j]=0;
      if (c=='#') A[i][j]=1;
    }
  }
  for (int i = 0; i < M; i++){
    for (int j = 0; j < M; j++){
      cin >> c;
      if (c=='.') B[i][j]=0;
      if (c=='#') B[i][j]=1;
    }
  }
  bool res = false;
  for (int i = 0; i <= N-M; i++){
    for (int j = 0; j <= N-M; j++){
      bool check = true;
      for (int k = 0; k < M; k++){
        for (int l = 0; l < M; l++){
          if (A[i+k][j+l] != B[k][l]) check = false;
        }
      }
      if (check) res = true;
    }
  }
  if (res){
    cout << "Yes";
  } else {
    cout << "No";
  }
}
