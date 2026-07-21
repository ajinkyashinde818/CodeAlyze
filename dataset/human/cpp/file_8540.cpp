#include<iostream>
#include <string>

using namespace std;

int main(){
  int N, M, flg=0;
  cin >> N >> M;
  string A[N], B[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  for (int i = 0; i < M; i++){
    cin >> B[i];
  }

  for (int i = 0; i < N - M + 1; i++){
    for (int j = 0; j < N - M + 1; j++){
      for (int k = 0; k < M; k++){
        if (A[i + k].substr(j, M) != B[k]) break;
        if (k == M - 1) flg = 1;
      }
    }
    if (flg == 1) break;
  }
  if (flg == 0) {
    printf("No\n");
  } else{
    printf("Yes\n");
  }
  
}
