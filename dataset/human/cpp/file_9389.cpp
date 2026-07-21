#include<iostream>
#include<string>
using namespace std;

int main() {
  int N, M;
  string A[50], B[50];
  int flag = 1;
  cin >> N >> M;

  for (int i = 0; i < N; i ++)
    cin >> A[i];

  for (int i = 0; i < M; i ++)
    cin >> B[i];

  for (int i = 0; i < N - M + 1 ; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      flag = 1;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[k + i][l + j] != B[k][l])
            flag = 0;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }

  if (flag == 0) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
