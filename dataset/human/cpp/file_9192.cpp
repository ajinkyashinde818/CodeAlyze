#include <iostream>
#include <string>
using namespace std;

int N, M;
string A[55], B[55];

int main() {
  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) cin >> B[i];

  bool finish = false;
  for (int i=0; i<=N-M; i++) {
    for (int j=0; j<=N-M; j++) {
      if (A[i][j] == B[0][0] && !finish) {
        bool flag = true;
        for (int k=0; k<M; k++) {
          for (int l=0; l<M; l++) {
            if (A[i+k][j+l] != B[k][l]) flag = false;
          }
        }
        if (flag) finish = true;
      }
    }
  }

  if (finish) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
