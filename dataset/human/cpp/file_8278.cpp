#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  char A[50][50], B[50][50];
  for(int i=0; i<N; ++i) scanf("%s", &A[i][0]);
  for(int i=0; i<M; ++i) scanf("%s", &B[i][0]);
  for(int Ay=0; Ay<=N-M; ++Ay) {
    for(int Ax=0; Ax<=N-M; ++Ax) {
      for(int y=0; y<M; ++y) {
        for(int x=0; x<M; ++x) {
          if(B[y][x] != A[Ay+y][Ax+x]) goto next;
        }
      }
      cout << "Yes" << endl;
      return 0;
      next:
      continue;
    }
  }
  cout << "No" << endl;
  return 0;
}
