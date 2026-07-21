#include <iostream>

using namespace std;

int main(){
  int N, M, flag;
  char A[51][51], B[51][51];

  cin >> N >> M;

  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      cin >> A[i][j];
    }
  }

  for(int i = 0;i < M;i++){
    for(int j = 0;j < M;j++){
      cin >> B[i][j];
    }
  }

  for(int i = 0;i <= N - M;i++){
    for(int j = 0;j <= N - M;j++){
      flag = 0;
      if(A[i][j] == B[0][0]){
        for(int k = 0;k < M;k++){
          for(int s = 0;s < M;s++){
            if(A[i + k][j + s] != B[k][s]){
              flag = 1;
            }
          }
        }
      } else {
        flag = 1;
      }
      if(flag == 0){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  if(flag == 1) cout << "No" << endl;

  return 0;

}
