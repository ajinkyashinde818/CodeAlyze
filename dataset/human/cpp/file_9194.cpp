#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string A[50], B[50];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  int same;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      same = 0;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i + k][j + l] == B[k][l]) same++;
        }
      }
      if (same == M * M) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
