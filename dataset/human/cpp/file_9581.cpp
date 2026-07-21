#include <iostream>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  char A[50][50];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  char B[50][50];
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
          if (A[i + x][j + y] != B[x][y]) {
            goto next;
          }
        }
      }
      cout << "Yes" << endl;
      return 0;
      next:;
    }
  }
  cout << "No" << endl;
  return 0;
}
