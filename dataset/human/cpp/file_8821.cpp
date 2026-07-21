#include <iostream>
#include <stdio.h>

using namespace std;

int A[51][51];
int B[51][51];
int N, M;

int solve(){
  for(int i = 0; i + M <= N; i++){
    for(int j = 0; j + M <= N; j++){
      int result = 1;
      for(int k = 1; k <= M; k++){
        for(int l = 1; l <= M; l++){
          //cout << k << " " << l << " " <<
          if(A[i+k][j+l] != B[k][l]){
            result = 0;
            l = M+1;
            k = M+1;
          }
        }
      }
      if(result == 1){
        cout << "Yes" << endl;
        i = N+1;
        j = N+1;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

int main(){
  char c;
  cin >> N >> M;

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> c;
      if(c == '#')  A[i][j] = 1;
      else A[i][j] = 0;
      //cout << A[i][j] << endl;
    }
  }
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= M; j++){
      cin >> c;
      if(c == '#') B[i][j] = 1;
      else B[i][j] = 0;
      //cout << B[1][1] << endl;
    }
  }
  int p = solve();

  return 0;

}
