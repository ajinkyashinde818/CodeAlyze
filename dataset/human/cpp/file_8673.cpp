#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  for(int sy = 0; sy <= N - M; sy++) {
    for(int sx = 0; sx <= N - M; sx++) {
      int flag = 0; 
      for (int tgty = 0; tgty < M; tgty++) {
        if (A[tgty + sy].substr(sx, M) != B[tgty]) continue;
        flag++;
      }
      if (flag == M) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
